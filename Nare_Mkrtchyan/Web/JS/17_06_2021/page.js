class PageRedirection {
    load() {
        this.items = [];
        this.page = 1;
        for(let i = 0; i < this.pageSize; ++i) {
            this.items[i] = this.arr[i];
            document.getElementById('ul').appendChild(this.items[i]);
        }
    }
    
    constructor(arr) {
        this.arr = arr;
        this.pageSize = 5;
        this.load();
    }

    setPageSize(pageSize) {
        let old = document.getElementsByClassName("a");
        for (let i = 0; i <= Math.floor(this.arr.length/this.pageSize); ++i) {
            old[0].remove();
        }
        for(let i = 1; i <= Math.ceil(elements.length/pageSize); ++i) {
            addPage(i);
        }

        updatePages();
        this.remove();
        this.pageSize = pageSize;
        this.load();
    }

    remove() {
        for (let item of this.items) {
            item.remove();
        }
    }

    changeColor(p1, p2) {
        let c = document.getElementById("page").childNodes;
        c[p1].style.backgroundColor = "white";
        c[p1].style.color = "black";
        c[p2].style.backgroundColor = "green";
        c[p2].style.color = "white";
    }

    displayItems(start,end) {
        this.remove();
        let j = 0;
        for(let i = start; i < end; ++i) {
            this.items[j] = this.arr[i];
            document.getElementById('ul').appendChild(this.items[j]);
            ++j;
        }
    }

    prevPage() {
        if (this.page > 1) {
            this.displayItems(this.pageSize*(this.page-2),this.pageSize*(this.page-1));
            --this.page;
            this.changeColor(this.page+2,this.page+1);
        } 
    }

    nextPage() {
        if (this.page < Math.floor(this.arr.length/this.pageSize)) {
            this.displayItems(this.pageSize*(this.page),this.pageSize*(this.page+1));
            ++this.page;
            this.changeColor(this.page,this.page+1);
        } else if (this.page == Math.floor(this.arr.length/this.pageSize)){
            this.remove();
            this.items = [];
            this.displayItems(this.pageSize*(this.page),this.arr.length);
            ++this.page;
            this.changeColor(this.page,this.page+1);
        } 
    }

    firstPage() {
        this.remove();
        for(let i = 0; i < this.pageSize; ++i) {
            this.items[i] = this.arr[i];
            document.getElementById('ul').appendChild(this.items[i]);
        }
        let p = this.page;
        this.page = 1;
        this.changeColor(p+1,this.page+1);
    }

    lastPage() {
        this.remove();
        this.items = [];
        this.displayItems((Math.ceil(this.arr.length/this.pageSize) - 1)*this.pageSize,this.arr.length);
        let p = this.page;
        this.page = Math.ceil(this.arr.length/this.pageSize);
        this.changeColor(p+1,this.page+1);
    }

    goToPage(pnumber) {
        if (pnumber > 0 && pnumber < Math.ceil(this.arr.length/this.pageSize)) {
            this.displayItems(this.pageSize*(pnumber-1),this.pageSize*(pnumber));
            this.changeColor(this.page+1,pnumber+1);
            this.page = pnumber;
        } else if(pnumber = Math.ceil(this.arr.length/this.pageSize)) {
            this.lastPage();
        } 
    }
}

let elements = document.querySelectorAll('ul > li');
for (let elem of elements) {
    elem.remove();
}
let el = new PageRedirection(elements);

let pr = document.createElement('a');
pr.setAttribute('href','#');
pr.setAttribute('id','prev');
document.getElementById("page").appendChild(pr);
pr.innerHTML = '<< Previous';

let nx = document.createElement('a');
nx.setAttribute('href','#');
nx.setAttribute('id','next');
document.getElementById("page").appendChild(nx);
nx.innerHTML = "Next >>";

for(let i = 1; i <= Math.ceil(elements.length/el.pageSize); ++i) {
    addPage(i);
}

function addPage(i) {
    let newEl = document.createElement('a');
    newEl.setAttribute("href", "#");
    newEl.setAttribute("class", "a");
    newEl.innerHTML = `${i}`;
    document.querySelector("#next").before(newEl);
}

document.getElementById("next").onclick = function(event) {
    el.nextPage()
};
document.getElementById("prev").onclick = function(event) {
    el.prevPage()
};

function updatePages() {
    let c = document.getElementById("page").childNodes;
    c.forEach((elem,ind) => {
    if (ind>1 && ind < c.length - 1) {
    elem.onclick = function(event) {
        el.goToPage(ind-1);
    };
}
})
};
updatePages();

function changeSizefunc() {
    let option = document.getElementById("pictures");
    let i = option.selectedIndex;
    el.setPageSize(option.options[i].text);
}
changeSizefunc()

document.getElementById("first").onclick = function(event) {
    el.firstPage();
};
document.getElementById("last").onclick = function(event) {
    el.lastPage();
};
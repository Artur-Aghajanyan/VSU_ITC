class PageRedirection {
    constructor(arr) {
        this.arr = arr;
        this.items = [];
        this.pageSize = 5;
        this.page = 1;
        for(let i = 0; i < this.pageSize; ++i) {
            this.items[i] = this.arr[i];
            this.items[i].style.display = "block";
        }
    }
    setPageSize(pageSize) {
        let old = document.getElementsByClassName("a");
        for (let i = 0; i <= Math.floor(this.arr.length/this.pageSize); ++i) {
            old[0].remove();
        }
        for(let i = 1; i <= Math.ceil(elements.length/pageSize); ++i) {
            addA(i);
        }
        function addA(i) {
            let newEl = document.createElement('a');
            newEl.setAttribute("href", "#");
            newEl.setAttribute("class", "a");
            newEl.innerHTML = `${i}`;
            document.querySelector("#next").before(newEl);
        }
        c = document.getElementById("page").childNodes;
        c.forEach((elem,ind) => {
            if (ind>1 && ind < c.length - 1) {
            elem.onclick = function(event) {
                el.goToPage(ind-1);
            };
        }
        })
        this.remove();
        this.pageSize = pageSize;
        this.items = [];
        this.page = 1;
        for(let i = 0; i < this.pageSize; ++i) {
            this.items[i] = this.arr[i];
            this.items[i].style.display = "block";
        }
    }
    remove() {
        for (let item of this.items) {
            item.style.display = "none";
        }
    }
    changeColor(p1, p2) {
        let c = document.getElementById("page").childNodes;
        c[p1].style.backgroundColor = "white";
        c[p1].style.color = "black";
        c[p2].style.backgroundColor = "green";
        c[p2].style.color = "white";
    }
    prevPage() {
        if (this.page > 1) {
            this.remove();
            let j = 0;
            for(let i = this.pageSize*(this.page-2); i < this.pageSize*(this.page-1); ++i) {
                this.items[j] = this.arr[i];
                this.items[j].style.display = "block";
                ++j;
            }
            --this.page;
            this.changeColor(this.page+2,this.page+1);
            return this.items;
        } else {
            return "You are on the first page."
        }
    }
    nextPage() {
        if (this.page < Math.floor(this.arr.length/this.pageSize)) {
            this.remove();
            let j = 0;
            for(let i = this.pageSize*(this.page); i < this.pageSize*(this.page+1); ++i) {
                this.items[j] = this.arr[i];
                this.items[j].style.display = "block";
                ++j;
            }
            ++this.page;
            this.changeColor(this.page,this.page+1);
            return this.items;
        } else if (this.page == Math.floor(this.arr.length/this.pageSize)){
            let j = 0;
            this.remove();
            this.items = [];
            for(let i = this.pageSize*(this.page); i < this.arr.length; ++i) {
                this.items[j] = this.arr[i];
                this.items[j].style.display = "block";
                ++j;
            }
            ++this.page;
            this.changeColor(this.page,this.page+1);
            return this.items;
        } else {
            return "You are on the last page."
        }
    }
    firstPage() {
        this.remove();
        for(let i = 0; i < this.pageSize; ++i) {
            this.items[i] = this.arr[i];
            this.items[i].style.display = "block";
        }
        let p = this.page;
        this.page = 1;
        this.changeColor(p+1,this.page+1);
        return this.items;
    }
    lastPage() {
        this.remove();
        this.items = [];
        let j = 0;
        for(let i = (Math.ceil(this.arr.length/this.pageSize) - 1)*this.pageSize; i < this.arr.length; ++i) {
            this.items[j] = this.arr[i];
            this.items[j].style.display = "block";
            ++j;
        }
        let p = this.page;
        this.page = Math.ceil(this.arr.length/this.pageSize);
        this.changeColor(p+1,this.page+1);
        return this.items;
    }
    goToPage(pnumber) {
        this.remove();
        if (pnumber > 0 && pnumber < Math.ceil(this.arr.length/this.pageSize)) {
            let j = 0;
            for(let i = this.pageSize*(pnumber-1); i < this.pageSize*(pnumber); ++i) {
                this.items[j] = this.arr[i];
                this.items[j].style.display = "block";
                ++j;
            }
            this.changeColor(this.page+1,pnumber+1);
            this.page = pnumber;
            return this.items;
        } else if(pnumber = Math.ceil(this.arr.length/this.pageSize)) {
            this.lastPage();
        } else {
            return `Page number must be from 0 to ${Math.floor(this.arr.length/this.pageSize)}`;
        } 
    }
}
let elements = document.querySelectorAll('ul > li');
for (let elem of elements) {
    elem.style.display = "none";
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
    addA(i);
}
function addA(i) {
    let newEl = document.createElement('a');
    newEl.setAttribute("href", "#");
    newEl.setAttribute("class", "a");
    newEl.innerHTML = `${i}`;
    document.querySelector("#next").before(newEl);
}
console.log(" ");
console.log("nextPage function` arr.nextPage()");
document.getElementById("next").onclick = function(event) {
    el.nextPage()
};
document.getElementById("prev").onclick = function(event) {
    el.prevPage()
};
let c = document.getElementById("page").childNodes;
c.forEach((elem,ind) => {
    if (ind>1 && ind < c.length - 1) {
    elem.onclick = function(event) {
        el.goToPage(ind-1);
    };
}
})
function changeSizefunc() {
    let option = document.getElementById("pictures");
    let i = option.selectedIndex;
    el.setPageSize(option.options[i].text);
}
document.getElementById("first").onclick = function(event) {
    el.firstPage();
};
document.getElementById("last").onclick = function(event) {
    el.lastPage();
};

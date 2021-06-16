class PageRedirection {
    #arr;
    #items;
    #pageSize;
    #page;
    constructor(arr) {
        this.#arr = arr;
        this.#items = [];
        this.#pageSize = 10;
        this.#page = 1;
        for(let i = 0; i < this.#pageSize; ++i) {
            this.#items[i] = this.#arr[i];
        }
        console.log(this.#items);
    }
    setPageSize(pageSize) {
        this.#pageSize = pageSize;
        this.#items = [];
        this.#page = 1;
        for(let i = 0; i < this.#pageSize; ++i) {
            this.#items[i] = this.#arr[i];
        }
        console.log(this.#items);
    }
    prevPage() {
        if (this.#page > 1) {
            let j = 0;
            for(let i = this.#pageSize*(this.#page-2); i < this.#pageSize*(this.#page-1); ++i) {
                this.#items[j] = this.#arr[i];
                ++j;
            }
            --this.#page;
            return this.#items;
        } else {
            return "You are on the first page."
        }
    }
    nextPage() {
        if (this.#page < Math.floor(this.#arr.length/this.#pageSize)) {
            let j = 0;
            for(let i = this.#pageSize*(this.#page); i < this.#pageSize*(this.#page+1); ++i) {
                this.#items[j] = this.#arr[i];
                ++j;
            }
            ++this.#page;
            return this.#items;
        } else if (this.#page == Math.floor(this.#arr.length/this.#pageSize)){
            let j = 0;
            this.#items = [];
            for(let i = this.#pageSize*(this.#page); i < this.#arr.length; ++i) {
                this.#items[j] = this.#arr[i];
                ++j;
            }
            ++this.#page;
            return this.#items;
        } else {
            return "You are on the last page."
        }
    }
    firstPage() {
        for(let i = 0; i < this.#pageSize; ++i) {
            this.#items[i] = this.#arr[i];
        }
        this.#page = 1;
        return this.#items;
    }
    lastPage() {
        this.#items = [];
        let j = 0;
        for(let i = (Math.ceil(this.#arr.length/this.#pageSize) - 1)*this.#pageSize; i < this.#arr.length; ++i) {
            this.#items[j] = this.#arr[i];
            ++j;
        }
        this.#page = Math.ceil(this.#arr.length/this.#pageSize);
        return this.#items;
    }
    goToPage(pnumber) {
        if (pnumber > 0 && pnumber < this.#arr.length/this.#pageSize) {
            let j = 0;
            for(let i = this.#pageSize*(pnumber-1); i < this.#pageSize*(pnumber); ++i) {
                this.#items[j] = this.#arr[i];
                ++j;
            }
            this.#page = pnumber;
            return this.#items;
        } else {
            return `Page number must be from 0 to ${Math.floor(this.#arr.length/this.#pageSize)}`;
        } 
    }
}
let arr1 = [];
for(let i = 0; i < 100; ++i) {
    arr1[i] = i;
}
console.log("Create object(Shows first page).");
let arr = new PageRedirection(arr1);
console.log(" ");
console.log("nextPage function` arr.nextPage()");
console.log(arr.nextPage());
console.log(" ");
console.log("lastPage function` arr.lastPage()");
console.log(arr.lastPage());
console.log(" ");
console.log("prevPage function` arr.prevPage()");
console.log(arr.prevPage());
console.log(" ");
console.log("setPageSize function (goes to first page)` arr.setPageSize(6)");
console.log(arr.setPageSize(6));
console.log(" ");
console.log("goToPage function (invalid input)` arr.goToPage(20)");
console.log(arr.goToPage(20));
console.log(" ");
console.log("goToPage function` arr.goToPage(6)");
console.log(arr.goToPage(6));
console.log(" ");
console.log("firstPage function` arr.firstPage()");
console.log(arr.firstPage());
console.log(" ");
console.log("prevPage function` arr.prevPage()");
console.log(arr.prevPage());
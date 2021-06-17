class Pagination {
    constructor(pageCount,pageSize) {
        this.pageCount = pageCount;
        this.pageSize = pageSize;
        this.items = [];

        this.last = this.pageSize;
        this.start = 0;
        this.lastItems = this.last;

        for (let i = 0; i < this.pageCount; i++) {
            this.items[i] = i;
        }

        this.printPage(this.start,this.last);
    }

    printPage(start,finish){
        let arr = [];
        let index = 0;
        for (let i = start;i < finish;i++) {
            arr[index] = this.items[i];
            index++;
        }
        console.log(arr)
    }

    nextPage() {
        this.start = this.lastItems;
        this.lastItems = this.start + this.last;
        if (this.lastItems > this.pageCount) {
            throw new Error("There is no such page")
        }
        this.printPage(this.start,this.lastItems);
    }

    prevPage() {
        this.start = this.start - this.last;
        this.lastItems = this.lastItems - this.last;
        if (this.start < 0) {
            throw new Error("There is no such page")
        }
        this.printPage(this.start,this.lastItems);
    }

    goToPage(page) {
        if (page > this.pageCount/this.pageSize || page < 1){
            throw new Error("There is no such page")
        }
        console.log("Go to Page ", page);
        this.lastItems = this.last * page;
        this.start = this.lastItems - this.last;
        this.printPage(this.start,this.lastItems);
    }

    lastPage() {
        this.lastItems = this.pageCount;
        this.start = this.lastItems - this.last;
        this.printPage(this.start,this.lastItems)
    }

    firstPage() {
        this.start = 0;
        this.lastItems = this.last;
        this.printPage(this.start,this.lastItems)
    }

}

let pageObj = new Pagination(150,10);

console.log("Next Page");
pageObj.nextPage();
console.log("Next Page");
pageObj.nextPage();
console.log("Next Page");
pageObj.nextPage();
console.log("Previous Page");
pageObj.prevPage();
pageObj.goToPage(15);
console.log("First Page");
pageObj.firstPage();
console.log("Last Page");
pageObj.lastPage();

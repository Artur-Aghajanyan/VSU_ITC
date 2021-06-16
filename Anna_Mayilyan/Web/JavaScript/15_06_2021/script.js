class Pagination {

    _arr;
    _curPage;
    _pageSize;
    _start;
    _arrsize;
    _divide;

    constructor(arr) {
        this.arr = arr;
        this.currentPage = 1;
        this.pageSize = 10;
        this.start = 0;
        this.arrsize = 0;
        this.arrsize = this.arr.length;
        this.divide = Math.ceil(this.arrsize / this.pageSize);
    }

    Func() {
        this.sliced = this.arr.slice(this.start, this.start + this.pageSize);
        console.log(this.sliced);
    }

    firstPage() {
        this.Func();
    }

    nextPage() {
        if (this.currentPage < this.divide)
           this.currentPage++;
        this.start = this.pageSize * (this.currentPage -1 );
        this.Func();
    }

    prevPage() {
        if (this.currentPage > 1)
            this.currentPage--;
        this.start = this.pageSize * (this.currentPage - 1);
        this.Func();
    }

    lastPage() {
        this.currentPage = this.divide;
        this.start = this.pageSize * (this.currentPage - 1);
        this.Func();
    }
}
let arr = [];
for (var i = 1; i <= 100; i++) {
    arr.push(i);
}
const s = new Pagination(arr);
s.firstPage()
s.nextPage()
s.nextPage()
s.nextPage()
s.nextPage()
s.prevPage()
s.lastPage()

class Pages{
    pageIndexStart = 0
    pageIndexEnd = 0
    pageIndex = 1

    constructor(array = [], size = 0){
        this.items = array
        this.pageSize = size
        if(this.pageSize > array.length){
            this.pageSize = array.length
        }
        this.pageIndexEnd = this.pageSize
    }

    Page(){
        console.log("Page ",this.pageIndex, " contain:")
        this.items.forEach((element, index) => {
            if(index >= this.pageIndexStart && index < this.pageIndexEnd){
                console.log(element)
            }
        });
    }

    nextPage(){
        this.pageIndexStart = this.pageIndexEnd
        this.pageIndexEnd += this.pageSize
        this.pageIndex ++
        this.Page()
    }

    prevPage(){
        this.pageIndexEnd = this.pageIndexStart
        this.pageIndexStart -= this.pageSize
        this.pageIndex --
        this.Page()
    }

    firstPage(){
        this.pageIndexStart = 0
        this.pageIndexEnd = this.pageSize
        this.pageIndex = 1
        this.Page()
    }

    lastPage(){
        this.pageIndexEnd = this.items.length
        this.pageIndexStart = this.pageSize * (Math.ceil(this.items.length / this.pageSize) - 1)
        this.pageIndex = Math.ceil(this.items.length / this.pageSize)
        this.Page()
    }

    goToPage(page){
        if(typeof(page) !== 'number')
        {
            console.log(page, " is not number!")
            return
        }
        if(page > Math.ceil(this.items.length / this.pageSize)){
            console.log("Page ", page, " not exist!")
            return
        }
        this.pageIndexEnd = page * this.pageSize
        this.pageIndexStart = this.pageIndexEnd - this.pageSize
        this.pageIndex = page
        this.Page()
    }
}

const arr = new Pages([1,2,3,4,5,6,7,8,9,10],2)
arr.Page()
arr.nextPage()
arr.prevPage()
arr.firstPage()
arr.lastPage()
arr.goToPage(3)
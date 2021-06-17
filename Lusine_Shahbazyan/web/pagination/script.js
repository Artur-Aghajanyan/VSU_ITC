class pagination
{
    firstIndex;
    lastIndex;

    constructor(array, size)
    {
        this.arrayPage = array;
        this.pageSize = size;
    }

    print(first, last)
    {
        let array = [];
        for(let i = first; i < last; ++i)
        {
            array.push(this.arrayPage[i]);
        }
        return array;
    }

    nextPage()
    {
        this.firstIndex = this.lastIndex;
        this.lastIndex += this.pageSize;
        return this.print(this.firstIndex, this.lastIndex);
    }

    prevPage()
    {
        this.firstIndex -= this.pageSize;
        this.lastIndex -= this.pageSize;
        return this.print(this.firstIndex, this.lastIndex);
    }

    firstPage()
    {
        this.firstIndex = 0;
        this.lastIndex = this.pageSize;
        return this.print(this.firstIndex, this.lastIndex);
    }

    lastPage()
    {
        this.firstIndex = this.pageSize * (Math.ceil(this.arrayPage.length / this.pageSize) - 1);
        this.lastIndex = this.arrayPage.length;
        return this.print(this.firstIndex, this.lastIndex);
    }

    goToPage(n)
    {
        this.lastIndex = n * this.pageSize;
        this.firstIndex = this.lastIndex - this.pageSize;
        return this.print(this.firstIndex, this.lastIndex);
    }
}

let array = [];
let pageSize = 10;
for(let i = 0; i < 100; ++i)
{
    array[i] = i;
}
let arrayOfPages = new pagination(array, pageSize);
console.log("Go to 7 page");
console.log(arrayOfPages.goToPage(7));
console.log("Go to previous page");
console.log(arrayOfPages.prevPage());
console.log("Go to naxt page");
console.log(arrayOfPages.nextPage());
console.log("Go to last page");
console.log(arrayOfPages.lastPage());
console.log("Go to first page");
console.log(arrayOfPages.firstPage());


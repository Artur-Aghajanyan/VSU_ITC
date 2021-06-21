class pagination
{
    firstIndex;
    lastIndex;

    constructor(array, size)
    {
        this.arrayPage = array;
        this.pageSize = size;
        let div = document.getElementById("div2");

        for(let i = 0; i < pageSize; i++)
        {
            let li1 = document.createElement("li");
            li1.classList.add("li1ID");
            li1.style.cursor = "pointer"
            li1.innerHTML = i + 1;
            li1.addEventListener("click", (event) => {
                let res= this.goToPage(event.target.innerText)
                this.printIntoHtml(res);
            })
            div.append(li1)
        }
        document.getElementById("next").addEventListener("click", () => {
            let res= this.nextPage()
            this.printIntoHtml(res);
        })
        document.getElementById("prev").addEventListener("click", () => {
            let res= this.prevPage()
            this.printIntoHtml(res);
        })
    }
    printIntoHtml(value)
    {
        let var1 = document.getElementById("items");
        var1.innerHTML = ""
        for(let i = 0; i < value.length; i++)
        {
            let li2 = document.createElement("li");
            li2.classList.add("li2ID");
            li2.style.backgroundColor = "#d672bd";
            li2.style.height = "1px"
            li2.style.display = "block"
            li2.style.border = "1px solid blue"
            li2.style.borderRadius = "25px"
            li2.innerHTML = value[i];
            var1.appendChild(li2);
        }
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
        console.log("hhhhhhh")
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
arrayOfPages.printIntoHtml(arrayOfPages.goToPage(1))


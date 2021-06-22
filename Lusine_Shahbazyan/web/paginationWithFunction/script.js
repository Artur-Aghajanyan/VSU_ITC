class Pagination
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
            if(i == 0) li1.classList.add("active");
            li1.addEventListener("click", (event) =>
            {
                let res= this.goToPage(event.target.innerText);
                let lis = document.getElementsByClassName("li1ID")
                for(let i = 0; i < lis.length; ++i)
                {
                    if(lis[i].classList.contains("active"))
                    {
                        lis[i].classList.remove("active")
                        lis[event.target.innerText - 1].classList.add("active")
                        break;
                    }
                }
                this.printIntoHtml(res);
            })
            div.append(li1)
        }

        document.getElementById("prev").addEventListener("click", () => 
        {
            let res1= this.prevPage()
            let lis = document.getElementsByClassName("li1ID")
            for(let i = 0; i < lis.length; ++i)
            {
                if(lis[i].classList.contains("active"))
                {
                    if(i - 1 >= 0){
                        this.printIntoHtml(res1);
                        lis[i].classList.remove("active")
                        lis[i - 1].classList.add("active")
                    }
                    break;
                }
            }
        })

        document.getElementById("next").addEventListener("click", () => 
        {
            let res= this.nextPage()
            let lis = document.getElementsByClassName("li1ID")
            for(let i = 0; i < lis.length; ++i)
            {
                if(lis[i].classList.contains("active"))
                {
                    if(i + 1 < this.pageSize){
                        this.printIntoHtml(res);
                        lis[i].classList.remove("active")
                        lis[i + 1].classList.add("active")
                    }
                    break;
                }
            }
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
            li2.style.backgroundColor = "#D672BD";
            li2.style.height = "1px"
            li2.style.display = "block"
            li2.style.border = "1px solid blue"
            li2.style.borderRadius = "25px"
            li2.innerHTML = value[i];
            var1.appendChild(li2);
        }
    }
    
    currentPage(first, last)
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
        return this.currentPage(this.firstIndex, this.lastIndex);
    }

    prevPage()
    {
        this.firstIndex -= this.pageSize;
        this.lastIndex -= this.pageSize;
        return this.currentPage(this.firstIndex, this.lastIndex);
    }

    goToPage(n)
    {
        this.lastIndex = n * this.pageSize;
        this.firstIndex = this.lastIndex - this.pageSize;
        return this.currentPage(this.firstIndex, this.lastIndex);
    }
}

let array = [];
let pageSize = 10;
for(let i = 0; i < 100; ++i)
{
    array[i] = i;
}
let arrayOfPages = new Pagination(array, pageSize);
arrayOfPages.printIntoHtml(arrayOfPages.goToPage(1))


class Pagination{
    array = []
    pageSize = 0
    newarray = []
    index = 0

    form = document.getElementById("form")
    general = document.getElementById("general")
    top = document.getElementById("top")
    bottom = document.getElementById("bottom")
    first = document.getElementById("first")
    prev = document.getElementById("prev")
    next = document.getElementById("next")
    last = document.getElementById("last")
    
    click(){
        this.array = document.getElementById("values").value.split(",")
        this.pageSize = parseInt(document.getElementById("size").value)
        
        for(let i = 0; i < Math.ceil(this.array.length / this.pageSize); i++){
            this.newarray[i] = this.array.slice(i * this.pageSize, i * this.pageSize + this.pageSize)
        }

        this.form.style.display = "none"
        this.general.style.display = "block"

        for(let i = 1; i <= this.pageSize; i++){
            const p = document.createElement("p")
            p.id = i
            p.innerHTML = this.newarray[0][i-1]
            this.top.appendChild(p)
        }

        for(let i = 1; i <= Math.ceil(this.array.length / this.pageSize); i++){
            const span = document.createElement("span")
            span.id = i
            span.innerHTML = i
            span.onclick = this.goToPage
            this.bottom.insertBefore(span, next)
        }

        //this.check()

    }

    check(){
        switch (this.index){
            case 0:
                this.first.style.display = "none"
                this.prev.style.display = "none"
                break
            case Math.ceil(this.array.length / this.pageSize):
                this.last.style.display = "none"
                this.next.style.display = "none"
                break
            default:
                this.first.style.display = "flex"
                this.prev.style.display = "flex"
                this.last.style.display = "flex"
                this.next.style.display = "flex"
        }
    }

    page(index){
        for(let i = 1; i <= this.pageSize; i++){
            const p = document.getElementById(i)
            if(this.newarray[index][i - 1] == undefined){
                p.innerHTML = ""
                continue
            }
            p.innerHTML = this.newarray[index][i-1]
        }
        //this.check()
    }

    nextPage(){
        this.index++
        this.page(this.index)
    }

    prevPage(){
        this.index--
        this.page(this.index)
    }

    firstPage(){
        this.index = 0
        this.page(this.index)
    }

    lastPage(){
        this.index = this.newarray.length - 1
        this.page(this.index)
    }

    goToPage(){
        this.index = 1;
        page1.page(this.index)
    }
}

const page1 = new Pagination()

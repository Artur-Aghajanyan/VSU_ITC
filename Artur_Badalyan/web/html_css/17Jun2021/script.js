class Pagination {
    constructor(pageCount, pageSize) {
        this.pageCount = pageCount;
        this.pageSize = pageSize;
        this.items = [];
        this.pagesItems = [];
        this.corPage = 0;
        this.last = this.pageSize;
        this.start = 0;
        this.lastItems = this.last;

        this.data_ul = document.querySelector('.data_ul');
        this.pages_ul = document.querySelector('.pages_ul');
        this.next_page = document.querySelector('.next_page');
        this.prev_page = document.querySelector('.prev_page');

        this.next_page.addEventListener('click', () => {
            this.nextPage();
            let lis = document.getElementsByClassName("page");
            this.corPage++;
            lis[this.corPage].classList.add("active");
            lis[this.corPage - 1].classList.remove("active");
        });

        this.prev_page.addEventListener('click', () => {
            let lis = document.getElementsByClassName("page");
            this.corPage--;
            lis[this.corPage].classList.add("active");
            lis[this.corPage + 1].classList.remove("active");
            this.prevPage();
        });

        this.appendDataElements(this.items);
        this.appendPagesElements(this.pagesItems);
        this.printData(this.start, this.last);
        this.printPages(this.start, this.last);
    }

    appendDataElements() {
        for (let i = 0; i < this.pageCount; i++) {
            this.items[i] = document.createElement('li');
            this.items[i].innerHTML = i;
        }
    }

    appendPagesElements() {
        for (let i = 0; i < this.pageSize; i++) {
            this.pagesItems[i] = document.createElement('li');
            this.pagesItems[i].addEventListener("click", (event) => {
                this.goToPage(event.target.innerText);
                let lis = document.getElementsByClassName("page");
                lis[this.corPage].classList.remove("active");
                lis[event.target.innerText - 1].classList.add("active");
                this.corPage = event.target.innerText - 1;
            });
            if (i === 0) {
                this.pagesItems[i].classList.add("active");
            }
            this.pagesItems[i].classList.add("page");
            this.pagesItems[i].innerHTML = i + 1;
        }
    }

    printData(start, finish) {
        this.data_ul.innerHTML = "";
        for (let i = start; i < finish; i++) {
            this.data_ul.append(this.items[i]);
        }
    }

    printPages(start, finish) {

        for (let i = start; i < finish; i++) {
            this.pages_ul.append(this.pagesItems[i]);
        }
    }

    nextPage() {
        this.start = this.lastItems;
        this.lastItems = this.start + this.last;
        if (this.lastItems > this.pageCount) {
            throw new Error("There is no such page");
        }
        this.printData(this.start, this.lastItems);
    }

    prevPage() {
        this.start = this.start - this.last;
        this.lastItems = this.lastItems - this.last;
        if (this.start < 0) {
            throw new Error("There is no such page");
        }
        this.printData(this.start, this.lastItems);
    }

    goToPage(page) {
        if (page > this.pageCount / this.pageSize || page < 1) {
            throw new Error("There is no such page");
        }
        this.lastItems = this.last * page;
        this.start = this.lastItems - this.last;
        this.printData(this.start, this.lastItems);
    }

    lastPage() {
        this.lastItems = this.pageCount;
        this.start = this.lastItems - this.last;
        this.printData(this.start, this.lastItems);
    }

    firstPage() {
        this.start = 0;
        this.lastItems = this.last;
        this.printData(this.start, this.lastItems);
    }
}

let pageObj = new Pagination(150, 10);


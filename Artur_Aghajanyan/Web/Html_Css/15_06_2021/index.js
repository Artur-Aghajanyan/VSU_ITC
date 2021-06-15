class Pagination {
  #pageEleArr;
  #numOfEleToDisplay;
  #elementCount;
  #numOfPages;
  #pageNo
  constructor(pageEleArr, size) {
    this.#pageEleArr = pageEleArr;
    this.#numOfEleToDisplay = size;
    this.#elementCount = this.#pageEleArr.length;
    this.#numOfPages = Math.ceil(this.#elementCount / this.#numOfEleToDisplay);
    this.#pageNo = 5;
  }

  pageElements(arr, eleDispCount) {
    const arrLen = arr.length;
    let pageArr = [];
    let perPageArr = [];
    let index = 0;
    let condition = 0;
    let remainingEleInArr = 0;

    for (let i = 0; i < this.#numOfPages; i++) {
      if (i === 0) {
        index = 0;
        condition = eleDispCount;
      }
      for (let j = index; j < condition; j++)
        perPageArr.push(arr[j]);

      pageArr.push(perPageArr);
      if (i === 0)
        remainingEleInArr = arrLen - perPageArr.length;
      else
        remainingEleInArr -= perPageArr.length;

      if (remainingEleInArr > 0) {
        if (remainingEleInArr > eleDispCount) {
          index += eleDispCount;
          condition += eleDispCount;
        }
        else {
          index = index + perPageArr.length;
          condition += remainingEleInArr;
        }
      }
      perPageArr = [];
    }
    return pageArr;
  }

  #display(pageNo) {
    if (pageNo > this.#numOfPages || pageNo <= 0)
      console.error('There is not page');

    else {
      console.log(`Elements into page ${pageNo}:`);
      let val = this.pageElements(this.#pageEleArr, this.#numOfEleToDisplay)[pageNo - 1];
      val.forEach(res => console.log(res));
      this.#pageNo = pageNo;
    }
  }

  prevPage() {
    console.log("################\n--- Start prevPage ---");
    console.log(`\nCurrent page ${this.#pageNo}, Prev Page wile be ${this.#pageNo-1}`);
    this.#display(this.#pageNo - 1);
    console.log("\n--- End prevPage ---\n****************\n\n");
  }

  nextPage() {
    console.log("################\n--- Start nextPage ---");
    console.log(`\nCurrent page ${this.#pageNo}, Next Page wile be ${this.#pageNo+1}`);
    console.log();
    this.#display(this.#pageNo + 1);
    console.log("\n--- End nextPage ---\n****************\n\n");
  }
  firstPage(){
    console.log("################\n--- Start firstPage ---");
    console.log(`\nCurrent page ${this.#pageNo}, Go to First page (page 1)`);
    this.#display(1);
    console.log("\n--- End firstPage ---\n****************\n\n");
  }
  lastPage(){
    console.log("################\n--- Start lastPage ---");
    console.log(`\nCurrent page ${this.#pageNo}, Go to Last page (page ${this.#numOfPages})`);
    this.#display(this.#numOfPages);
    console.log("\n--- End lastPage ---\n****************\n\n");
  }
  goToPage(index){
    console.log("################\n--- Start goToPage ---");
    console.log(`\nCurrent page ${this.#pageNo}, Go to Page ${index}`);
    this.#display(index);
    console.log("\n--- End goToPage ---\n****************\n\n");
  }
}

fetch('https://jsonplaceholder.typicode.com/todos')
.then(response => response.json())
.then(res => {
  const pagination = new Pagination(res, 6);

  pagination.nextPage();
  pagination.prevPage();
  pagination.firstPage();
  pagination.lastPage();
  pagination.goToPage(25);
  pagination.goToPage(3000);
})



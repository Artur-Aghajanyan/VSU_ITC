let items = [];
let pageCount = 150;
let pageSize = 10;

function printPage(array,start,finish){
    let arr = [];
    index = 0;
    for (let i = start;i < finish;i++) {
        arr[index] = array[i];
        index++;
    }
    console.log(arr)
}

for (let i = 0; i < pageCount; i++) {
    items[i] = i;
}

let last = pageSize;
let start = 0;
let lastItems = last;

printPage(items,start,last);

function nextPage() {
    console.log("Next Page");
    start = lastItems;
    lastItems = start + last;
    if (lastItems > pageCount) {
        throw new Error("There is no such page")
    }
    printPage(items,start,lastItems);
    console.log("----------");
}

function prevPage() {
    console.log("Previous Page");
    start = start - last;
    lastItems = lastItems - last;
    if (start < 0) {
        throw new Error("There is no such page")
    }
    printPage(items,start,lastItems);
    console.log("----------");
}

function goToPage(page) {
    if (page > pageCount/pageSize || page < 1){
        throw new Error("There is no such page")
    }
    console.log("Go to Page ", page);
    lastItems = last * page;
    start = lastItems - last;
    printPage(items,start,lastItems);
}

function lastPage() {
    console.log("Last Page");
    lastItems = pageCount;
    start = lastItems - last;
    printPage(items,start,lastItems)
}

function firstPage() {
    console.log("First Page");
    start = 0;
    lastItems = last;
    printPage(items,start,lastItems)
}

nextPage();
nextPage();
nextPage();
prevPage();
goToPage(15);
firstPage();
lastPage();

class Pagination {
    _items = [];
    _pageSize = 10;

    constructor(items, pageSize) {
        this._items = items;
        this._pageSize = pageSize;
    }

    page(pageNumber) {
        let index = 0;
        let array = [];

        for (let i = (pageNumber-1)*this._pageSize; i < pageNumber*this._pageSize; ++i) {
            array[index] = this._items[i];
            ++index;
        }

        return array;
    }
}

const array = [];
const size = 10;

for (let i = 0; i < 100; ++i) {
    array[i] = i + 1;
}

let pagination = new Pagination(array, size);

console.log(pagination.page(6));

const f1 = () => "1";
const f2 = () => () => "2";
const f3 = () => () => () => "3";
const f4 = "666";

function funcCount(func) {
    let count = 0;

    while(typeof(func) === 'function') {
        ++count;
        func = func();
    }

    return count;
}

function sort(array1, array2, len) {
    for (let i = 0; i < len; ++i) {
        for (let j = i+1; j < len; ++j) {
            if (array2[i] > array2[j]) {
                c = array1[i];
                d = array2[i];
                array1[i] = array1[j];
                array2[i] = array2[j];
                array1[j] = c;
                array2[j] = d;
            }
        }
    }

    return array2;
}

let array1 = [f2, f3, f1, f4];
let index = 0;
let array2 = [];

for (let i of array1) {
    array2[index]=funcCount(i);
    ++index;
}

console.log(sort(array1,array2,index));

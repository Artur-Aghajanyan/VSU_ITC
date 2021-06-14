f1 = () => () => console.log('f1');
f2 =  () => () => () => console.log('f2');
f3 = () => () => () => () => console.log('f3');

//counts calls
function counter(el, ind) {  
    while(typeof el === 'function'){
        el = el()
        countArr[ind]++;
    } 
}

//sorts
function sortFunc(arr1) {
    arr2 = arr1;
    countArr = new Array(arr2.length).fill(0);
    arr2.forEach((element, index) => counter(element, index));
    for(let i = 0; i < arr2.length; ++i) {
        for(let j = i+1; j < arr2.length; ++j) {
            if(countArr[i] > countArr[j]) {
                c = countArr[i];
                countArr[i] = countArr[j];
                countArr[j] = c;
                a = arr2[i];
                arr2[i] = arr2[j];
                arr2[j] = a;
            }
        }
    }
    return arr2;
}

console.log(sortFunc([f2,f3,f1]));
console.log(sortFunc([f1,f2,f3]));
console.log(sortFunc([f1,"f2",f3]));

f1 = () => "hello"
f2 = () => () => "edabit"
f3 = () => () => () => "user"

function swap(arr, xp, yp) {
    let temp = arr[xp];
    arr[xp] = arr[yp];
    arr[yp] = temp;
}

function funcSort(arr) {
    let newArray = [...arr];
    for(let i = 0; i < newArray.length; ++i){
        for (let j = 0; j < newArray.length - i - 1; ++j){
            let a = newArray[j]();
            let b = newArray[j+1]();
            while(true){
                if(typeof (a) != "function")
                    break

                if(typeof (b) != "function") {
                    swap(newArray, j, j+1)
                    break
                }

                a = a();
                b = b();
            }
        }
    }
    return newArray;
}
let array = [f2, f3, f1];
console.log(array, " My Array,")
let newArray = funcSort(array);
console.log(newArray, " New Array")


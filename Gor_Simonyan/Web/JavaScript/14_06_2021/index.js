const f1 = () => "Called 1"
const f2 = () => () => "Called 2"
const f3 = () => () => () => "Called 3"
const f4 = () => () => () => () => "Called 4"
const f5 = () => () => () => () => () => "Called 5"
const f_txt = "text, Called 0"

let count = 0

function FuncCallCount(func){
    try{
        count++
        if (typeof(func()) === 'function')
        {
            FuncCallCount(func())
        }
        return count
    }
    catch{
        return 0
    }
}

function sort(arr){
    let count_call = arr.map(func => {
        count = 0
        return FuncCallCount(func)})
    for (let i = 0; i < arr.length; i++){
        for (let index = 0; index < arr.length-i; index++){
            if (count_call[index] > count_call[index+1]){
                [arr[index], arr[index + 1]] = [arr[index + 1], arr[index]];
                [count_call[index], count_call[index + 1]] = [count_call[index + 1], count_call[index]]
            }
        }
    }
    return arr
}

console.log("Before sorting: ", [f5,f1,f3,f_txt,f2,f4], "\nAfter sorting:", sort([f5,f1,f3,f_txt,f2,f4]))
f1 = () => () => () => "hello"
f2 = () => () => "edabit"
f3 = () => () => () => "user"

let array = [f1,f2,f3]

function callFoo(array,arr1,arr2,index) {
    let foo1 = arr1()
    let foo2 = arr2()
    while(true) {
        if(typeof foo1 != "function"){
            break;
        }
        if(typeof foo2 != "function"){
            let temp = array[index]
            array[index] = array[index+1]
            array[index+1] = temp
            break;
        }
        foo1 = foo1();
        foo2 = foo2();
    }
}

function sorting (arr){
    let array = [...arr];
    for (let i = 0; i < array.length; i++) {
        for (let j = 0; j < array.length - i - 1; j++) {
            callFoo(array,array[j],array[j+1],j)
        }
    }
    return array
}

console.log("----------- Array Before -----------")
console.log(array)

console.log("----------- Array After -----------")
console.log(sorting(array))
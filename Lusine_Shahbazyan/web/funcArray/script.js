f1 = () => "hello";
f2 = () => () => "edabit";
f3 = () => () => () => "user";
let funcArray = [f2, f3, f1];

console.log("Befor sorting");
console.log(funcArray);
let count = 0;
function countOfCall(func)
{
    count++;
    if (typeof(func()) === 'function')
    {
        countOfCall(func());
    }
    return count;
}

function swap(arr, i, j)
{
    let temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

function funcSort(arr)
{
    for (let i = 0; i < arr.length; i++)
    {
        for (let j = 0; j < arr.length - i - 1; j++)
        {
            let value1 = countOfCall(arr[j]);
            let value2 = countOfCall(arr[j + 1]);
            if(value1 > value2)
            {
                swap(arr, j + 1, j);
            }
        }
    }
    return arr;
}

let sortedArray = funcSort(funcArray);
console.log("After sorting")
console.log(sortedArray)


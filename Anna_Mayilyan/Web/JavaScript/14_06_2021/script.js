f1 = _ => "hello"
f2 = _ => _ => "edabit"
f3 = _ => _ => _ => "user"


var count = 0;
var array = [f3, f1, f2];
 function sortFunc(a){
       if(typeof a =="function")
       {
        a = a();
        count++;
        sortFunc(a);
        return count;
       }
}
var myMap = new Map()
for(i = 0; i < array.length; i++)
   {
    let f = sortFunc(array[i]);
     myMap.set(array[i], f);
    count = 0;
}
    console.log(myMap);
    var myNewMap = new Map([...myMap.entries()].sort());
    console.log(myNewMap);


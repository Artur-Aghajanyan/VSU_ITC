let f1 = () => 'hello';
let f2 = () => () => 'two' ;
let f3 = () => () => () => 'three';
function check(arg) {
	let count = 0;
	while (typeof(arg) === 'function') {
		arg = arg();
		++count;
	}
	
	return count;
}
let a=check(f1);
let b=check(f2);
let c=check(f3);
console.log(a,b,c);

let my_array=[f3,f1,f2];
function Sort(array) {
	let value = array.sort((start,end) => check(start)-check(end));
	console.log(value)
}

Sort(my_array);

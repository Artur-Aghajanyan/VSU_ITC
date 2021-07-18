function pow(baseNumber, power) {
    if (power === 1) {
        return baseNumber * power;
        } else
        return baseNumber * pow(baseNumber, power - 1);
};
     
function factorial(num) {
    if (num < 0) 
        return -1;
    else if (num == 0) 
        return 1;
    else {
        return (num * factorial(num - 1));
    };
};           

function division(x, y) {
    if (y != 0) 
        return x / y;
};

function squareRoot(number) {
    var number;
    for (var i = number; i >= 1; i--) {
        if (i * i === number) {
            number = i;
            break;
       };
   };
   return number;
};

module.exports = { pow, factorial, division, squareRoot }

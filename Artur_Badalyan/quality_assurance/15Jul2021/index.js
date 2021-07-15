function pow(x,y){
    let pow = 1;
    while(y > 0) {
        pow *= x;
        --y;
    }
    return pow;
}

module.exports = {pow};
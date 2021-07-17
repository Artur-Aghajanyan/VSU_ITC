function test1 (x, y) {
    return x > y;
}

function test2 (x, y) {
    return x < y;
}

function test3 (x, y) {
    return x === y;
}

function test4 (x, y) {
    return x + y > 10;
}

function test5 (x, y) {
    return x - y === 0;
}
module.exports = { test1, test2, test3, test4, test5 }
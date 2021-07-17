function sum(val1, val2) {
  if(val1 < 1 || val2 < 1) {
    return -1;
  } else{
    return val1 + val2;
  }
}

module.exports = { sum };
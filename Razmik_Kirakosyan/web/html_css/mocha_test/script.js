function pow(baseNumber, power) {
    if (power === 1) {
        return baseNumber * power
    } else 
    return baseNumber * pow(baseNumber, power - 1)
} 

module.exports = { pow }
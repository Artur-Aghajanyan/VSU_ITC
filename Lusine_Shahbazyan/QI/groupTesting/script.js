exports.isNumValid = function(num) {
    if (num > 0) {
        return true
    }

    if (num <= 0) {
        return false
    }

    if(20 % num == 0) {
        return true
    }

    if(num % 2 == 0) {
        return true
    } 
    
    if(num % 2 != 0) {
        return true
    }

}
var assert = require('assert');

    var { pow } = require('./script.js');
    var { factorial } = require('./script.js');

    describe("smoke_group", function() {
        it("basenumber raises to n-th power", function() {
            assert.equal(pow(4, 2), 16);
        });
        it("to count to factorial for given number", function() {
            assert.equal(factorial(4), 24);
        });
        
    });
    
    var { division } = require('./script.js');
    describe("numbers division", function() {
        it("to divide given numbers", function() {
        assert.equal(division(4, 2), 2);
        });
    })
    
    var { squareRoot } = require('./script.js');
    describe("square root", function() {
        it("to count square root for given number", function() {
        assert.equal(squareRoot(0), 0);
        });
    })
  
const chai = require('chai');
const assert = chai.assert;
const expect = chai.expect;
const {pow} = require('./index');

describe("pow", function() {

    it("When raising 2 to the 3rd power, the result is 8", function() {
        assert.equal(pow(2, 3), 8);
    });

    it("When raising 3 to the 4th power, the result is 81", function() {
        assert.equal(pow(3, 4), 81);
    });

    it("We are waiting for number", function() {
        expect(pow(5,8)).to.be.a('number');
    });

});

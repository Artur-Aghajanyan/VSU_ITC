const chai = require('chai');
const expect = chai.expect;
const validator = require('./script.js');

describe("function isNumValid()", () => {
	it("should return true for a number in between 10 and 70", ()=> {
		expect(validator.isNumValid(39)).to.be.true
	});

	it("should return false when the number is less than or equal to 10", () => {
		expect(validator.isNumValid(10)).to.be.false
	});

	it("should return false when the number is greater than or equal to 70", () => {
		expect(validator.isNumValid(79)).to.be.false
	});
});
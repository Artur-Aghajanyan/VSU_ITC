const should = require('chai').should();
const app = require('../index');

describe('(group1): Three tests', () => {
    describe('sum', function () {
        it('should add numbers', function () {
            app.sum(6, 2).should.be.eql(8);
        });
    });
	
    describe('sub', function () {
        it('should subtract numbers', function () {
            app.sub(13, 4).should.be.eql(9);
        });
    });
	
    describe('mul', function () {
        it('should muliply numbers', function () {
            app.mul(3, 5).should.be.above(14);
        });
    });
});

describe('(group2): Other tests', () => {
    describe('div', function () {
        it('should divide numbers', function () {
            app.div(24, 8).should.be.equal(3);
        });
    });
	
    describe('rem', function () {
        it('should return the reminder of numbers', function () {
            app.rem(71, 4).should.be.equal(3);
        });
    });
});

const chai = require('chai');
const expect = chai.expect;
const validator = require('./script.js');

describe('test1', () => {
    it('return true if number is even', () => {
        expect(validator.isNumValid(4)).to.be.true;
    });
});
            
describe('test2', () => {
    it('return false if number is odd', () => {
        expect(validator.isNumValid(3)).to.be.true
    });
});


describe('smoke group test', () => {
    describe('test3', () => {
        it('return true if number is greater then 0', () => {
            expect(validator.isNumValid(12)).to.be.true
        });
    });
	
    describe('test4', () => {
        it('return false if number is less or equel 0', () => {
            expect(validator.isNumValid(-3)).to.be.false
        });
    });
	
    describe('test5', () => {
        it('return true if the number is divicer of 20', () => {
            expect(validator.isNumValid(5)).to.be.true
        });
    });
});



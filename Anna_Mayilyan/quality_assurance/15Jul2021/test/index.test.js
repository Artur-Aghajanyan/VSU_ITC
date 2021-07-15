const should = require('chai').should();
const app = require('../index');
describe('# App test', function () {
    describe('# sayHello', function () {
        it('should return hello', function () {
            app.sayHello().should.equal('hello');
        });
        it('should a string type', function () {
            app.sayHello().should.be.a('string');
        });
    });
    describe('# addNumbers', function () {
        it('should greater than 5', function () {
            app.addNumbers(3, 4).should.be.above(5);
        });
    });
    describe('# subNumbers', function () {
        it('should greater than 3', function () {
            app.subNumbers(5, 1).should.be.above(3);
        });
        describe('# multNumbers', function () {
            it('should greater than 10', function () {
                app.multNumbers(3, 4).should.be.above(10);
            });
        });
    });
});




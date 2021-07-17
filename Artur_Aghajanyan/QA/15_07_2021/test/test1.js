const assert = require('chai').assert;
const should = require('chai').should();
const expect = require('chai').expect;
const app = require('../index')

describe('Count positive numbers sum', () => {
    it('Must to return 11 (5+6)', function () {
        assert.equal(app.sum(5, 6), 11);
    });
});

describe('Try to count not positive numbers sum', () => {
    it('should return -1 when the value is not positive', function () {
        should.equal(app.sum(-5, 6), -1);
    });
});

describe('Try to count not positive numbers sum', () => {
    it('Expect return 25 (19+6)', function () {
        expect(app.sum(19, 6)).to.equal(25);
    });
});
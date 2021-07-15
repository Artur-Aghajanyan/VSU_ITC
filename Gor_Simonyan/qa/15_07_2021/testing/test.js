const chai = require('chai')
const { test } = require('./index')

const expect = chai.expect

describe("test summer function", () => {
    it("return true (x > y)", () => {
        expect(test(10,5)).to.be.true
    })

    it("return false (x < y)", () => {
        expect(test(5,10)).to.be.false
    })

    it("return false (x = y)", () => {
        expect(test(5,5)).to.be.false
    })
})
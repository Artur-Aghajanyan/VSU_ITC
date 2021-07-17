const chai = require('chai')
const { test1, test2, test3, test4, test5 } = require('./index')

const expect = chai.expect

describe("all tests", () => {
    describe("test1 function", () => {
        it("return true (x > y)", () => {
            expect(test1(10,5)).to.be.true
        })

        it("return false (x < y)", () => {
            expect(test1(5,10)).to.be.false
        })

        it("return false (x = y)", () => {
            expect(test1(5,5)).to.be.false
        })
    })

    describe("test2 function", () => {
        it("return false (x > y)", () => {
            expect(test2(10,5)).to.be.false
        })

        it("return true (x < y)", () => {
            expect(test2(5,10)).to.be.true
        })

        it("return false (x = y)", () => {
            expect(test2(5,5)).to.be.false
        })
    })

    describe("test3 function", () => {
        it("return false (x > y)", () => {
            expect(test3(10,5)).to.be.false
        })

        it("return false (x < y)", () => {
            expect(test3(5,10)).to.be.false
        })

        it("return true (x = y)", () => {
            expect(test3(5,5)).to.be.true
        })
    })

    describe("test4 function", () => {
        it("return true (x + y > 10)", () => {
            expect(test4(10,5)).to.be.true
        })

        it("return false (x + y < 10)", () => {
            expect(test4(5,1)).to.be.false
        })

        it("return false (x + y = 10)", () => {
            expect(test4(5,5)).to.be.false
        })
    })

    describe("test5 function", () => {
        it("return true (x - y = 0)", () => {
            expect(test5(10,10)).to.be.true
        })

        it("return false (x - y < 10)", () => {
            expect(test5(5,10)).to.be.false
        })

        it("return false (x - y > 10)", () => {
            expect(test5(10,5)).to.be.false
        })
    })
})
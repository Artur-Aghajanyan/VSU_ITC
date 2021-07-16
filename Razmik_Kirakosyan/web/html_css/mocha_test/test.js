var assert = require('assert');
var { pow } = require('./script.js');
describe("pow", function() {

    it("basenumber raises to n-th power", function() {
      assert.equal(pow(2, 3), 8);
    });
  
  })
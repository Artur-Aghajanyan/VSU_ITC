var events = require('events');
var eventEmitter = new events.EventEmitter();
var fs = require('fs');

var listner1 = function listner1() {
    fs.readFile('a.txt', function (err, data) {
        if (err) throw err;
        if(data.includes('hello')){
            console.log(data.toString('utf8'))
        }
    });
}

eventEmitter.addListener('find', listner1);
eventEmitter.emit('find');

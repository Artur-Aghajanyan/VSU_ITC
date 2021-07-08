var events = require('events');
var eventEmitter = new events.EventEmitter();
var fs = require('fs');

eventEmitter.on('find', () => {
    console.log('succed');
    return 0;
});

fs.readFile('a.txt', function (err, data) {
    if (err) throw err;
    if(data.includes('hello')){
        eventEmitter.emit('find');
    } else {
        console.log("String not found");
    }
});

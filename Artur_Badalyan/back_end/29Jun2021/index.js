const EventEmitter = require('events');
const myEmitter = new EventEmitter();

myEmitter.on('event', function stringFound() {
    console.log('Event worked! String found');
});

require("fs").readFile("text.txt", function(err, data) {
    if (err)
        throw err;
    data.indexOf("ipsum") > -1 ? myEmitter.emit('event') : console.log("String not found");
});

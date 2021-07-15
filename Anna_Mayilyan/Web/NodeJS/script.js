var events  = require("events");
var fs  = require("fs");
var eventsEmitter = new events.EventEmitter();

eventsEmitter.on('check', checkWord);
eventsEmitter.on('found', Found);
eventsEmitter.on('failed', failFunction);

    fs.readFile("file.txt", 'utf8', (error, data) => {
        if (error) {
            console.log(error);
        } eventsEmitter.emit('check', data);
    });
  
function checkWord(data) {
    if (data.includes("text ")) {
        eventsEmitter.emit('found');
    } else {
        eventsEmitter.emit('failed');
    }
}

function Found() {
    console.log('The word has been found successfuly');
}

function failFunction() {
    console.log('The word does not exist!');
}







const event = require('events');
const fs = require('fs');

let myEmit  = new event.EventEmitter();

myEmit.on('my_event', function(text){
    console.log("I found your text` ",text);
});

const search_string = "name";

fs.readFile("./text.txt", function(err, data){
    if (err) throw err;
    if(data.includes(search_string)){
        myEmit.emit('my_event', search_string);
    }
});
let events = require('events');
let eventEmitter = new events();
let fs = require('fs');
let keyword = "Node.js";

eventEmitter.on('event',myEventHandler => {
    console.log("String found and Events happened");
});


fs.readFile("text.txt", function(err, content){
    if(err)
        throw err;
    content.indexOf(keyword) > -1 ? eventEmitter.emit('event') : console.log("String not found");});
    



var events = require('events');
var my_Emit = new events.EventEmitter();
my_Emit.on('some_event', function(text) {
	console.log(text);
});
const fs = require("fs");
fs.readFile("/home/razmik/nodejs_event" +"/file.txt", (error, my_file) => {
    if(error) {
        throw error;
    } if(my_file.includes("Horatio")) {

    my_Emit.emit('some_event', "The name Horacio was founded");
	}
});



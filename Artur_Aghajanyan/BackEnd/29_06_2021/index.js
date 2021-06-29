var findInFiles = require('find-in-files');
const EventEmitter = require("events");
findInFiles.find("Lorem", './', 'text.txt')
	.then(function(results) {
        for (var result in results) {
            var res = results[result];
          class MyEmitter extends EventEmitter {}
          const myEmitter = new MyEmitter();
          myEmitter.on("event", () => console.log('an event occurred'));
          myEmitter.emit('event');
          return 0;
        }
    });


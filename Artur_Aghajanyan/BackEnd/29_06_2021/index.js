const findInFiles = require('find-in-files');
const EventEmitter = require('events');

class MyEmitter extends EventEmitter {}
const myEmitter = new MyEmitter();
myEmitter.on('event', () => console.log('an event occurred'));

findInFiles.find('Lorem', './', 'text.txt').then(function(results) {
  for (var result in results) {
    var res = results[result];
    myEmitter.emit('event');
    return 0;
  }
});


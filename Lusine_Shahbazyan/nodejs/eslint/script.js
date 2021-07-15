let events = require('events');
let eventEmitter = new events.EventEmitter();
let myEventHandler = function () {
    console.log('Event happened');
}
eventEmitter.on('event', myEventHandler);
eventEmitter.emit('event');

const findInFiles = require('find-in-files');
const EventEmitter = require('events');

class MyEmitter extends EventEmitter {}

const myEmitter = new MyEmitter();
myEmitter.on('event', () => {
  // eslint-disable-next-line no-console
  console.log('an event occurred');
  return 0;
});

findInFiles.find('Lorem', './', 'text.txt').then((results) => {
  // eslint-disable-next-line guard-for-in,no-restricted-syntax
  for (const result in results) {
    const res = results[result];
    // eslint-disable-next-line no-console
    console.log(res);
    myEmitter.emit('event');
    return 0;
  }
  return 1;
});

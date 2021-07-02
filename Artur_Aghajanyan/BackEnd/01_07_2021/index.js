const express = require('express');
const fs = require('fs');

const app = express();

const host = '127.0.0.1';
const port = 7000;


let checkFile = function(req, res, next) {
  fs.readFile('text.txt', 'utf8', (err, data) => {
    if (err) {
      throw err;
    }
    const arr = data.toString().replace(/\r\n/g,'\n').split('\n');

    if(arr.length < req.query.id) {
      res.status(404).send(`In File Not found Line ${req.query.id}`);
    }
  });
}

app.get('/home',checkFile, (req, res) => {
  console.log("aaaa");
  fs.readFile('text.txt', 'utf8', (err, data) => {
    if (err) {
      throw err;
    }
    const arr = data.toString().replace(/\r\n/g,'\n').split('\n');
    res.send(arr[req.query.id - 1]);
  });
});

app.use((req, res, next) => {
  res.status(404).type('text/plain');
  res.send('Not found');
});

app.listen(port, host, () => console.log(`Server listens http://${host}:${port}`));

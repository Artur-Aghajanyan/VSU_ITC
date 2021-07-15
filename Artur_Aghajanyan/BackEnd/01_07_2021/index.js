const express = require('express');
const fs = require('fs');
const bodyParser = require('body-parser');
const app = express();

const host = '127.0.0.1';
const port = 7000;

app.use(bodyParser.json());

// Middleware Start
let checkFile = function(req, res, next) {
  fs.readFile('text.txt', 'utf8', (err, data) => {
    if (err) {
      throw err;
    }
    const arr = data.toString().replace(/\r\n/g, '\n').split('\n');

    if (arr.length < req.query.id) {
      res.status(404).send(`In File Not found Line ${req.query.id}`);
    }
    else {
      next();
    }
  });
};

let checkNumber = (req, res, next) => {
  const checkNum = /^[A-Za-z]+$/;
  const text = req.body.text;
  if (checkNum.test(text)) {
    next();
  }
  else {
    res.status(400);
    res.end('Error');
  }
};
// Middleware End

app.get('/get', checkFile, (req, res) => {
  fs.readFile('text.txt', 'utf8', (err, data) => {
    if (err) {
      throw err;
    }
    const arr = data.toString().replace(/\r\n/g, '\n').split('\n');
    res.send(arr[req.query.id - 1]);
  });
});

app.post('/post', checkNumber, (req, res) => {
  const text = req.body.text;
  fs.appendFile('text.txt', `\n${text}`, (err, data) => {
    if (err) {
      throw err;
    }
    res.status(200);
    res.end('Append Text into file');
  });
});

app.put('/put', checkNumber, checkFile, (req, res) => {
  const text = req.body.text;
  fs.readFile('text.txt', 'utf8', (err, data) => {
    if (err) {
      throw err;
    }
    const arr = data.toString().replace(/\r\n/g, '\n').split('\n');
    res.send(arr[req.query.id - 1]);
    let id = req.query.id;
    arr[id - 1] = text;
    let newArr = [];
    arr.forEach((item, index) => {
      console.log(item, index);
      arr[index] = item + '\n';
    });
    fs.writeFile('text.txt', arr.join(''), (err, data) => {
      if (err) {
        throw err;
      }
      res.status(200);
      res.end(`Change Line ${id} to ${text}`);
    });
  });
});

app.delete('/delete', checkFile, (req, res) => {
  fs.readFile('text.txt', 'utf8', (err, data) => {
    if (err) {
      throw err;
    }
    const arr = data.toString().replace(/\r\n/g, '\n').split('\n');
    res.send(arr[req.query.id - 1]);

    let id = req.query.id;
    arr.splice(id - 1, 1);
    arr.forEach((item, index) => {
      console.log(item, index);
      arr[index] = item + '\n';
    });
    fs.writeFile('text.txt', arr.join(''), (err, data) => {
      if (err) {
        throw err;
      }
      res.status(200);
      res.end(`Delete Text from Line ${id} Into File`);
    });
  });
});

app.use((req, res, next) => {
  res.status(404).type('text/plain');
  res.send('Not found');
});

app.listen(port, host, () => console.log(`Server listens http://${host}:${port}`));


const express = require('express');
const app = express();
const port = 3001;

app.get('/', (req, res) => {
  console.log('Got request GET');
  res.send('Send request GET!');
});

app.post('/', (req, res) => {
  console.log('Got request POST');
  res.send('Send request POST!');
});

app.delete('/', (req, res) => {
  console.log('Got request delete');
  res.send('Send request Delete!');
});

app.put('/', (req, res) => {
  console.log('Got request put');
  res.send('Send request PUT!');
});

app.listen(port, () => {
  console.log(`Example app listening at http://localhost:${port}`);
});

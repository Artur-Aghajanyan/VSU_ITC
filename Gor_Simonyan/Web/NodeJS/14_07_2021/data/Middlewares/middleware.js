const express = require('express');
const bodyParser = require('body-parser');

const app = express();

app.use(bodyParser.json());
app.use(bodyParser.raw());

const re = /^[A-Za-z]+$/;

const check = app.use(async (req, res, next) => {
    if (req.method !== "Get" && re.test(req.body.name) === false) res.status(404).send("not ok");
    else next();
});

module.exports = { check };
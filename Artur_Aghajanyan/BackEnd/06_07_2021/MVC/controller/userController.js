const bodyParser = require('body-parser');
const express = require('express');
const models = require('../models/user');

const app = express();
app.use(bodyParser.json());
const getUser = (req, res) => {
  models.User.findOne({
    where: {
      id: req.query.id,
    },
  }).then((r) => {
    res.send(JSON.stringify({
      id: r.id,
      name: r.firstName,
      surname: r.lastName,
    }));
  });
};

const postUser = (req, res) => {
  if (req.body.name && req.body.surname) {
    models.User.create({
      firstName: req.body.name,
      lastName: req.body.surname,
    }).then((r) => {
      r.save().then(() => console.log('ok')).catch((err) => res.send(JSON.stringify(err)));
      res.status(200);
      res.end('OK');
    }).catch((err) => {
      res.end(JSON.stringify(err));
    });
  } else {
    res.status(400);
    res.end('Error');
  }
};

const putUser = (req, res) => {
  if (req.body.name && req.body.surname) {
    models.User.update(
      {
        firstName: req.body.name,
        lastName: req.body.surname,
      },
      { where: { id: req.query.id } },
    ).then(() => {
      res.status(200);
      res.end('OK');
    }).catch((err) => {
      res.end(err);
    });
  } else {
    res.status(400);
    res.end('Error');
  }
};

const deleteUser = (req, res) => {
  // eslint-disable-next-line no-console
  console.log(req.query.id);
  models.User.destroy({ where: { id: req.query.id } }).then(() => {
    res.status(200);
    res.end('OK');
  }).catch((err) => {
    res.end(err);
  });
};

module.exports = {
  getUser, postUser, putUser, deleteUser,
};

const { Sequelize, DataTypes, Model } = require('sequelize');
const express = require('express');
const bodyParser = require('body-parser');

const app = express();
const host = '127.0.0.1';
const port = 7000;

app.use(bodyParser.json());

const sequelize = new Sequelize('test', 'root', '', {
  host: '127.0.0.1',
  dialect: 'mysql',
  port: 3306,
});

class User extends Model {}

async function testForConnecting() {
  try {
    await sequelize.authenticate();
    // eslint-disable-next-line no-console
    console.log('Connection has been established successfully.');

    User.init({
      id: {
        type: DataTypes.INTEGER,
        autoIncrement: true,
        primaryKey: true,
      },
      firstName: {
        type: DataTypes.STRING,
        allowNull: false,
      },
      lastName: {
        type: DataTypes.STRING,
      },
    }, {
      sequelize,
      // timestamps: false,
      modelName: 'users',
    });
    await User.sync({ alter: true });
  } catch (error) {
    // eslint-disable-next-line no-console
    console.error('Unable to connect to the database:', error);
  }
}

testForConnecting().then(() => {
  const checkID = (req, res, next) => {
    const checkNum = /^[A-Za-z]+$/;
    const { id } = req.query;
    if (!checkNum.test(id)) {
      User.findAll().then((response) => {
        response.forEach((item) => {
          if (item.id === +id) next();
        });
      });
    } else {
      res.status(400);
      res.end('Error');
    }
  };
  app.get('/', checkID, (req, res) => {
    User.findOne({
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
  });

  app.post('/post', (req, res) => {
    if (req.body.name && req.body.surname) {
      User.create({
        firstName: req.body.name,
        lastName: req.body.surname,
      }).then((r) => {
        r.save();
        res.status(200);
        res.end('OK');
      }).catch((err) => {
        res.end(JSON.stringify(err));
      });
    } else {
      res.status(400);
      res.end('Error');
    }
  });
  app.put('/put', checkID, (req, res) => {
    if (req.body.name && req.body.surname) {
      User.update(
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
  });
  app.delete('/delete', checkID, (req, res) => {
    console.log(req.query.id);
    User.destroy({ where: { id: req.query.id } }).then(() => {
      res.status(200);
      res.end('OK');
    }).catch((err) => {
      res.end(err);
    });
  });
});

// eslint-disable-next-line no-console
app.listen(port, host, () => console.log(`Server listens https://${host}:${port}`));

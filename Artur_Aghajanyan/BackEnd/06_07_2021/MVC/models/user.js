const { Sequelize, DataTypes, Model } = require('sequelize');
const bodyParser = require('body-parser');

const express = require('express');

const app = express();

const sequelize = new Sequelize('test', 'root', '', {
  host: '127.0.0.1',
  dialect: 'mysql',
  port: 3306,
});

app.use(bodyParser.json());

class User extends Model {}
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
User.sync({ alter: true }).then(() => console.log('ok')).catch((err) => console.log(err));
module.exports = User;

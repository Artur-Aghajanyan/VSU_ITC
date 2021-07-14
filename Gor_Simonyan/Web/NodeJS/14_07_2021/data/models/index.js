const Sequelize = require('sequelize');

const sequelize = new Sequelize("server",'root','7777',{
    dialect: "mysql",
    host: "127.0.0.1"
});

module.exports = sequelize;
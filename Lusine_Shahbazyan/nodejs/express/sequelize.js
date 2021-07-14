const { Sequelize } = require('sequelize');
const express = require('express');

const app = express();
const sequelize = new Sequelize('Sequelize', 'root', 'Dell001$', {    //'Sequelize' is name of database
    host: 'localhost',
    dialect: 'mysql'
});

async function asyncCall() {
    try {
        await sequelize.authenticate();
        console.log('Connection has been established successfully.');
    } catch (error) {
        console.error('Unable to connect to the database:', error);
    }
}

asyncCall();

app.listen(3030, 'localhost', () => {
    console.log('ok');
})

var express = require('express');
var Sequelize = require('sequelize');
var x = require('body-parser');
const Cors = require ('cors');
const swaggerUi = require ('swagger-ui-express');
const swaggerDocument = require ('./swagger.json');
var app = express();
app.use(x.json());
app.use(Cors());

const seq = new Sequelize('User', 'root','151516',{
    dialect: "mysql",
    host: "127.0.0.1"
});

const user_table = seq.define('user_table', {
    id: {
        type: Sequelize.INTEGER,
        autoIncrement: true,
        allowNULL: false,
        primaryKey: true
    },

    us_name: {
        type: Sequelize.STRING,
        allowNULL: false
    }
},
{
    timestamps: false
});

const cars_table = seq.define('cars_table', {
    id: {
        type: Sequelize.INTEGER,
        autoIncrement: true,
        allowNULL: false,
        primaryKey: true
    },

    car_model_name: {
        type: Sequelize.STRING,
        allowNULL: false
    }
},
{
    timestamps: false
});

module.exports = user_table;
module.exports = cars_table;
seq.sync({force: true });


app.get('/users', function (req, res) {
    user_table.findAll().then(table_content => res.send(table_content));
});

app.post('/users', async function (req, res) {
    await user_table.create({us_name: req.body.name}).then(table => table.save());
    user_table.findAll().then(table => res.send(table));
});

app.put('/users', async function (req,res) {
    await user_table.update({us_name: req.body.name},{where: {id: req.body.id}});
    user_table.findAll().then(table => res.send(table));
});

app.delete('/users', async function (req, res) {
    await user_table.destroy({where: { id: req.body.id}});
    user_table.findAll().then(table => res.send(table));
});

app.get('/cars', function (req, res) {
    cars_table.findAll().then(table_content => res.send(table_content));
});

app.post('/cars', async function (req, res) {
    await cars_table.create({car_model_name: req.body.carModel}).then(table => table.save());
    cars_table.findAll().then(table => res.send(table));
});

app.put('/cars', async function (req,res) {
    await cars_table.update({car_model_name: req.body.carModel},{where: {id: req.body.id}});
    cars_table.findAll().then(table => res.send(table));
});

app.delete('/cars', async function (req, res) {
    await cars_table.destroy({where: { id: req.body.id}});
    cars_table.findAll().then(table => res.send(table));
});

app.use('/swagger', swaggerUi.serve, swaggerUi.setup(swaggerDocument));
app.listen(8081);

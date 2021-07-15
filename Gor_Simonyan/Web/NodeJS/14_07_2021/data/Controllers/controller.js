const data = require('../models/data');
const animals = require('../models/animals');
const cars = require('../models/cars');
const company = require('../models/company');
const bodyParser = require('body-parser');
const express = require('express');
const sequelize = require('../models/index');

sequelize.sync({ force: true });

const app = express();

app.use(bodyParser.json());
app.use(bodyParser.raw());

async function GetUsers (req, res) {
    data.findAll().then(table => res.send(table));
}

async function PostUsers (req, res) {
    await data.create({name: req.body.name}).then(table => table.save());
    data.findAll().then(table => res.send(table));
}

async function PutUsers (req, res) {
    await data.update({name: req.body.name}, {where: {id: req.body.id}});
    data.findAll().then(table => res.send(table));
}

async function DeleteUsers (req, res) {
    await data.destroy({where: {id: req.body.id}});
    data.findAll().then(table => res.send(table));
}

async function GetAnimals (req, res) {
    animals.findAll().then(table => res.send(table));
}

async function PostAnimals (req, res) {
    await animals.create({name: req.body.name, age: req.body.age}).then(table => table.save());
    animals.findAll().then(table => res.send(table));
}

async function PutAnimals (req, res) {
    await animals.update({name: req.body.name, age: req.body.age}, {where: {id: req.body.id}});
    animals.findAll().then(table => res.send(table));
}

async function DeleteAnimals (req, res) {
    await animals.destroy({where: {id: req.body.id}});
    animals.findAll().then(table => res.send(table));
}

async function GetCars (req, res) {
    cars.findAll().then(table => res.send(table));
}

async function PostCars (req, res) {
    await cars.create({mark: req.body.mark, year: req.body.year}).then(table => table.save());
    cars.findAll().then(table => res.send(table));
}

async function PutCars (req, res) {
    await cars.update({mark: req.body.mark, year: req.body.year}, {where: {id: req.body.id}});
    cars.findAll().then(table => res.send(table));
}

async function DeleteCars (req, res) {
    await cars.destroy({where: {id: req.body.id}});
    cars.findAll().then(table => res.send(table));
}

async function GetCompany (req, res) {
    company.findAll().then(table => res.send(table));
}

async function PostCompany (req, res) {
    await company.create({company: req.body.company, budget: req.body.budget}).then(table => table.save());
    company.findAll().then(table => res.send(table));
}

async function PutCompany (req, res) {
    await company.update({company: req.body.company, budget: req.body.budget}, {where: {id: req.body.id}});
    company.findAll().then(table => res.send(table));
}

async function DeleteCompany (req, res) {
    await company.destroy({where: {id: req.body.id}});
    company.findAll().then(table => res.send(table));
}

module.exports = { GetUsers, PostUsers, PutUsers, DeleteUsers, GetAnimals, PostAnimals, PutAnimals, DeleteAnimals, GetCars, PostCars, PutCars, DeleteCars, GetCompany, PostCompany, PutCompany, DeleteCompany };
const data = require('../models/data')
const bodyParser = require('body-parser')
const express = require('express')

const app = express()

app.use(bodyParser.json())
app.use(bodyParser.raw())

async function Get(req, res){
    console.log("Got a GET request for the homepage")
    data.findAll().then(table => res.send(table))
}

async function Post(req, res){
    console.log("Got a POST request for the homepage")
    await data.create({name: req.body.name}).then(table => table.save())
    data.findAll().then(table => res.send(table))
}

async function Put(req, res){
    console.log("Got a PUT request for the homepage")
    await data.update({name: req.body.name}, {where: {id: req.body.id}})
    data.findAll().then(table => res.send(table))
}

async function Delete(req, res){
    console.log("Got a DELETE request for homepage")
    await data.destroy({where: {id: req.body.id}})
    data.findAll().then(table => res.send(table))
}

module.exports = { Get, Post, Put, Delete }
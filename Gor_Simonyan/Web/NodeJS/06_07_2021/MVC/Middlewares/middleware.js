const express = require('express')
const bodyParser = require('body-parser')
const data = require('../models/data')

const app = express()

app.use(bodyParser.json())
app.use(bodyParser.raw())

const re = /^[A-Za-z]+$/

const check = app.use(async (req, res, next) => {
    let bool = true
    if (req.method === "POST" && re.test(req.body.name) === false) res.status(404).send("not ok")
    else if (req.method === "PUT") {
        await data.findOne({ where: {id: req.body.id}}).then(element => {
            if (element === null) {
                bool = false
            }})
        if (re.test(req.body.name) === false || bool === false) res.status(404).send("not ok")
        else next()
    }
    else if (req.method === "DELETE") {
        await data.findOne({where: {id: req.body.id}}).then(element => {
            if (element === null) {
                bool = false
            }
        })
        if (bool === false) res.status(404).send("not ok")
        else next()
    }
    else next()
})

module.exports = { check }
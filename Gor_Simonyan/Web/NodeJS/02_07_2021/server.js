const express = require('express')
const bodyParser = require('body-parser')
const Sequelize = require('sequelize')

const app = express()

const sequelize = new Sequelize("server",'root','7777',{
        dialect: "mysql",
        host: "127.0.0.1",
})

const data = sequelize.define("data", {
        id : {
                type: Sequelize.INTEGER,
                autoIncrement: true,
                primaryKey: true,
                allowNull: false
        },
        name: {
                type: Sequelize.STRING,
                allowNull: false
        }
},
    {
            timestamps: false,
    })

module.exports = data

sequelize.sync()

let body = ""
let bodyKey = ""
let bodyVal = ""

app.use(bodyParser.urlencoded({ extended: true }))
app.use(bodyParser.json())
app.use(bodyParser.raw())

const re = /^[A-Za-z]+$/

app.use(function(req, res, next) {
        body = req.body
        bodyKey = +(Object.keys(body))
        bodyVal = Object.values(body)
        if ((req.method === "POST" || req.method === "PUT") && (re.test(bodyVal) === false)) res.status(404).send("not ok")
        else next()
})

app.get('/', function (req, res) {
        console.log("Got a GET request for the homepage")
        data.findAll().then(table => res.send(table))
})

app.post('/', async function (req, res) {
        console.log("Got a POST request for the homepage")
        await data.create({name: bodyVal[0]}).then(table => table.save())
        data.findAll().then(table => res.send(table))
})

app.put('/', async function (req,res){
        console.log("Got a PUT request for the homepage")
        await data.update({name: bodyVal[0]},{where: {id: bodyKey}})
        data.findAll().then(table => res.send(table))
})

app.delete('/', async function (req, res) {
        console.log("Got a DELETE request for /del_user")
        await data.destroy({where: { id: bodyKey}})
        data.findAll().then(table => res.send(table))
})

app.listen(8081)
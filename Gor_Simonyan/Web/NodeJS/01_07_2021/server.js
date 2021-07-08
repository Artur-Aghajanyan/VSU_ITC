const express = require('express')
const bodyParser = require('body-parser')
const fs = require('fs')

const app = express()

fs.exists("text.txt", exists => {
    if (exists === false){
        fs.appendFile("text.txt",'File created',error => {
            if (error) throw error
            }
        )
    }
})

let array = []
let body = ""
let bodyKey = ""
let bodyVal = ""

app.use(bodyParser.urlencoded({ extended: true }))
app.use(bodyParser.json())
app.use(bodyParser.raw())

const re = /^[A-Za-z]+$/

function write() {
    fs.writeFile('./text.txt', "",(error) => {
        if (error) throw error
    })
}

app.use(function(req, res, next) {
    array = fs.readFileSync('text.txt').toString().split("\n")
    body = req.body
    bodyKey = +(Object.keys(body))
    bodyVal = Object.values(body)
    if (req.method === "GET") next()
    else if ((req.method === "POST" && re.test(bodyVal) === false) ||
        (req.method === "PUT" && (re.test(bodyVal) === false || bodyKey > array.length)) ||
        (req.method === "DELETE" && bodyKey > array.length)){
            res.send("not ok")
    }
    else next()
})

app.get('/', function (req, res) {
    console.log("Got a GET request for the homepage")
    fs.readFile("./text.txt",'utf-8', function (error, data) {
        res.send(data)
    })
})

app.post('/', function (req, res) {
    console.log("Got a POST request for the homepage")
    fs.appendFile("./text.txt", "\n" + bodyVal, (error) => {
        if (error) throw error
    })
    fs.readFile("./text.txt",'utf-8', function (error, data) {
        res.send(data)
    })
})

app.put('/', function (req,res){
    console.log("Got a PUT request for the homepage")
    array.splice(bodyKey - 1,1,bodyVal)
    write()
    array.forEach((value, index) => {
        if (index < array.length - 1) value += "\n"
        fs.appendFile("./text.txt", value, (error) => {
            if (error) throw error
        })
    })
    fs.readFile("./text.txt",'utf-8', function (error, data) {
        res.send(data)
    })
})

app.delete('/', function (req, res) {
    console.log("Got a DELETE request for /del_user")
    array.splice(bodyKey - 1,1)
    write()
    array.forEach((value, index) => {
        if (index < array.length - 1) value += "\n"
        fs.appendFile("./text.txt", value, (error) => {
            if (error) throw error
        })
    })
    fs.readFile("./text.txt",'utf-8', function (error, data) {
        res.send(data)
    })
})

app.listen(8081)

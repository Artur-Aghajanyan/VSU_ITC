const express = require('express');
const bodyParser = require('body-parser');
const fs = require('fs')

fs.exists("text.txt", exists => {
    if (exists === false){
        fs.open("text.txt",'wx',error => {
            if (error){
                throw error
            }
        })
    }
})

const app = express();

app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json());
app.use(bodyParser.raw());

const re = /^[A-Za-z]+$/

function write(){
    fs.writeFile('./text.txt', "",(error) => {
        if (error){
            throw error
        }
    });
}

app.get('/', function (req, res) {
    console.log("Got a GET request for the homepage");
    fs.readFile("./text.txt",'utf-8', function (error, data)
    {res.send(data)})
})
app.post('/', function (req, res) {
    console.log("Got a POST request for the homepage");
    const body = req.body
    const bodyVal = Object.values(body)
    if (re.test(bodyVal)){
        fs.appendFile("./text.txt", "\n" + bodyVal, (error) => {
            if (error){
                throw error;
            }})
        fs.readFile("./text.txt",'utf-8', function (error, data)
        {res.send(data)})
    }
    else {
        res.send('Number error')
    }
})
app.put('/', function (req,res){
    console.log("Got a PUT request for the homepage");
    const array = fs.readFileSync('text.txt').toString().split("\n")
    const body = req.body
    const bodyKey = +(Object.keys(body))
    const bodyVal = Object.values(body)
    if (re.test(bodyVal)){
        if (array.length >= bodyKey - 1){
            array.splice(bodyKey - 1,1,bodyVal)
            write()
            array.forEach((value, index) => {
                if (index < array.length - 1){
                    value += "\n"
                }
                fs.appendFile("./text.txt", value, (error) => {
                    if (error){
                        throw error;
                    }})
            })
            fs.readFile("./text.txt",'utf-8', function (error, data)
            {res.send(data)})
        }
    }
    else {
        res.send('Number error');
    }
})
app.delete('/', function (req, res) {
    console.log("Got a DELETE request for /del_user");
    const array = fs.readFileSync('text.txt').toString().split("\n")
    const body = req.body
    const bodyKey = +(Object.keys(body))
    if (array.length >= bodyKey - 1){
        array.splice(bodyKey - 1,1)
        write()
        array.forEach((value, index) => {
            if (index < array.length - 1){
                value += "\n"
            }
            fs.appendFile("./text.txt", value, (error) => {
                if (error){
                    throw error;
                }})
        })
        fs.readFile("./text.txt",'utf-8', function (error, data)
        {res.send(data)})
    }
    else {
        res.send('Number error');
    }
})
app.listen(8081)
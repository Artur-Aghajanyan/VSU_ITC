var express = require('express');
var app = express();
var fs = require('fs');
var replace = require('replace-in-file');
var lineReplace = require('line-replace');
var logger = fs.createWriteStream('a.txt', {
    flags: 'a'
})

app.use(function (req, res, next) {
    function hasNumber(myString) {
        return /\d/.test(myString);
    }

    let y = false;

    fs.readFile('a.txt', 'utf8', function(err, data) {
        if(err) console.log("ERROR");

        const arr = data.toString().split('\n');

        for(let i of arr) {
            let x = hasNumber(i);
            if (x == true) {
                y = true;
            }
        }

        if (y === false) {
            next();
        }
        else {
            res.send("Error. Text file includes numberes.")
        }
    })
})

app.get('/', function (req, res) {
    fs.readFile('a.txt', function (err, data) {
        if (err) console.log("ERROR");
        if(data){
            res.send(data);
        }
    });
})

app.put('/', function (req, res) {
    lineReplace({
        file: 'a.txt',
        line: 2,
        text: 'blablabla',
        addNewLine: true,
        callback: ({ file, line, text, replacedText, error }) => {
            fs.readFile(file, function (err, data) {
                if (err) console.log("ERROR");
                if (data){
                    res.send(data);
                }
            });
        }
    });
})

app.post('/', function (req, res) {
    logger.write('blablabla');
    fs.readFile('a.txt', function (err, data) {
        if (err) console.log("ERROR");
        if(data){
            res.send(data);
        }
    });
})

app.delete('/', function (req, res) {
    lineReplace({
        file: 'a.txt',
        line: 2,
        text: '',
        addNewLine: true,
        callback: ({ file, line, text, replacedText, error }) => {
            fs.readFile(file, 'utf8', function (err, data) {
                if (err) throw err;
                if (data){
                    res.send(data.replace(/[\r\n]+/g, '\n'));
                }
            });
        }
    });
})

app.listen(8080)

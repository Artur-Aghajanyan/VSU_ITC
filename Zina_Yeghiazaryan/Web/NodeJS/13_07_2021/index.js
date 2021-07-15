onst swaggerUi = require('swagger-ui-express');
const swaggerDocument = require('./swagger.json');
const cors = require('cors');

var express = require('express');
var app = express();
var fs = require('fs');
var lineReplace = require('line-replace');
var logger = fs.createWriteStream('a.txt', {
    flags: 'a'
});

app.use(function (req, res, next) {
    function hasNumber(myString) {
        return /\d/.test(myString);
    }

    let y = false;

    fs.readFile('a.txt', 'utf8', function(err, data) {
        if(err) res.send("Error.");

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
            res.send("Error. Text file includes numberes.");
        }
    });
});

app.get('/', function (req, res) {
//    fs.readFile('a.txt', function (err, data) {
//        if (err) res.send("Error.");
//        if(data){
            res.send({message:"go to hell"});
//        }
//    });
});

app.put('/', function (req, res) {
    lineReplace({
        file: 'a.txt',
        line: 2,
        text: 'blablabla',
        addNewLine: true,
        callback: ({ file, line, text, replacedText, error }) => {
            fs.readFile(file, function (err, data) {
                if (err) res.send("Error.");
                if (data){
                    res.send(data);
                }
            });
        }
    });
});

app.post('/', function (req, res) {
    logger.write('blablabla');
    fs.readFile('a.txt', function (err, data) {
        if (err) res.send("Error");
        if(data){
            res.send(data);
        }
    });
});

app.delete('/', function (req, res) {
    lineReplace({
        file: 'a.txt',
        line: 2,
        text: '',
        addNewLine: true,
        callback: ({ file, line, text, replacedText, error }) => {
            fs.readFile(file, 'utf8', function (err, data) {
                if (err) res.send(err);
                if (data){
                    res.send(data.replace(/[\r\n]+/g, '\n'));
                }
            });
        }
    });
});

app.get('/users', (req, res) => {
    res.send({
        id: "1222333",
        email: "s@s.com"
    });
})

app.use('/api-docs', swaggerUi.serve, swaggerUi.setup(swaggerDocument));
app.use(cors());

app.listen(8083);                                                        

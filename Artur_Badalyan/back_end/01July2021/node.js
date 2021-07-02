const express = require('express');
const bodyParser = require('body-parser');
const app = express();
const port = 8080;
const file = 'data.txt';
const fs = require("fs");

app.use(bodyParser.json());

app.get('/', (req, res) => {
    console.log('Got request GET');
    fs.readFile('data.txt', 'utf8', (err, file) => {
        if (err)
            throw err;
        res.send(file);
    });
});


app.post('/', (req, res) => {
    const body = req.body;
    const bodyValue = Object.values(body);
    console.log(bodyValue);
    const text = /^[A-Za-z]+$/;
    if (text.test(bodyValue)) {
        res.status(200);
        fs.appendFile(file, '\n' + bodyValue, function (err) {
            if (err)
                throw err;

            console.log("\nFile Contents of file after post:\n\n",
                fs.readFileSync(file, "utf8"));
        });
        res.send('The text is added to the file and saved');
    } else {
        res.status(404);
        res.send('The imported text cannot be numbers');
    }
});

app.put('/put', (req, res) => {
    const body = req.body;
    const bodyValue = Object.values(body);

    fs.readFile(file, 'utf8', function (err, data) {
        if (err) {
            throw err;
        }
        let result = data.toString().replace(/\r\n/g, '\n').split('\n');
        if (bodyValue[1] < result.length) {
            res.status(200);
            result.forEach((item,index) => {
                if (index == bodyValue[1]){
                    item = bodyValue[0];
                }
                result[index] = item + '\n';
            })

            fs.writeFile(file, result.join(""), function (err) {
                if (err)
                    throw err;
                console.log("\nFile Contents of file after put:\n\n",
                    fs.readFileSync(file, "utf-8"));
            });

            res.send('The text is replaced to the file and saved');
        } else {
            res.status(400);
            res.send('There were no such lines found');
        }
    });
});

app.delete('/delete', (req, res) => {
    const body = req.body;
    const bodyValue = Object.values(body);

    let result = fs.readFileSync(file,"utf-8").split('\n');
    if (bodyValue[1] < result.length) {
        res.status(200);
        for (let i = 0; i < result.length; ++i) {
            if (i == bodyValue[1]) {
                result.splice(i, 1);
            }
            result[i] = result[i] + '\n';
        }
        res.send('The line is deleted to the file and saved');
    } else {
        res.status(400);
        res.send('There were no such lines found');
    }
    fs.writeFile(file,result.join(), function (err) {
        if(err)
            throw err;
    })
});


app.listen(port, () => {
    console.log(`Example app listening at http://localhost:${port}`);
});

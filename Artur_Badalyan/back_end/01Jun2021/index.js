const express = require('express');
const bodyParser = require('body-parser');
const app = express();
const port = 8080;
const file = 'data.txt';
const fs = require("fs");

// app.use(bodyParser.json());

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

            console.log("\nFile Contents of file after append:\n\n",
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
            for (let i = 0; i < result.length; ++i) {
                if (i = bodyValue[1]) {
                    result[i] = bodyValue[0];
                }
            }
            fs.writeFile(file, result, function (err) {
                if (err)
                    throw err;
                console.log("\nFile Contents of file after put:\n\n",
                    fs.readFileSync(file, "utf8"));
            });

            res.send('The text is replaced to the file and saved');
        } else {
            res.send('There were no such lines found');
        }
    });
});

app.delete('/', (req, res) => {
    console.log('Got request delete');
    res.send('Send request Delete!');
});


app.listen(port, () => {
    console.log(`Example app listening at http://localhost:${port}`);
});


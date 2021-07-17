let express = require('express');
let app = express();
let fs = require("fs");
let file = 'text.txt';
let bodyParser = require("body-parser");
const { Recoverable } = require('repl');
let router = express.Router();

app.get('/', function (req, res) {
    fs.readFile('text.txt', (err, file) => {
        if (err)
            throw err;
        res.send(file);
    })
});


app.put('/', function (req, res) {
    res.send('Put method')
})

app.delete('/', function (req, res) {
    console.log(req);
    console.log()
    res.send('Delete method')
})

app.post('/', function (req, res) {
    res.send('Post method')
})

fs.readFile(file, 'utf8', function(err, data)
{
    if (err)
    {
        // check and handle err
    }
    // data is the file contents as a single unified string
    // .split('\n') splits it at each new-line character and all splits are aggregated into an array (i.e. turns it into an array of lines)
    // .slice(1) returns a view into that array starting at the second entry from the front (i.e. the first element, but slice is zero-indexed so the "first" is really the "second")
    // .join() takes that array and re-concatenates it into a string
    var linesExceptFirst = data.split('\n').slice(1).join('\n');
    fs.writeFile(filename, linesExceptFirst);
});
// app.use(bodyParser.urlencoded({ extended: false }));
// app.use(bodyParser.json());

// router.post('/handle',(req,res) => {
//     console.log(request.body);
// });
// app.use("/", router);

app.listen(8080);
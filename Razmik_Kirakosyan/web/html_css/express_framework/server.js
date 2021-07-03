var express = require('express');
var app = express();
const fs = require('fs')
const x = require('body-parser')

app.use(x.json())


app.get('/', function (req, res) {
    fs.readFile('./data.txt', 'utf8' , (err, file_content) => {
        if (err) {
          console.error(err)
          return
        }
        res.send(file_content);
      })
   
})

app.post('/', function (req, res) {
    const content = req.body;
    const value = Object.values(content);
    fs.appendFile('./data.txt', "\n" + value[0], function (err) {
        if (err) throw err;
        
      });
      fs.readFile('./data.txt', 'utf8' , (err, file_content) => {
        if (err) {
          console.error(err)
          return
        }
        res.send(file_content);
      })       
    })


app.put('/', function (req, res){
    const content = req.body;
    const value = Object.values(content);
    const key = +(Object.keys(content));
    const array = fs.readFileSync("data.txt").toString().split("\n")
    array[key-1] = value[0];
    console.log(array);
    fs.writeFile('./data.txt', "", function (err) {
        if (err) throw err;
        }); 
    array.forEach((element,index) => { if (index != array.length-1) {
        element += "\n";
        fs.appendFile("./data.txt", element, function(error) {if(error) throw error} )
    }})
    fs.readFile('./data.txt', 'utf8' , (err, file_content) => {
        if (err) {
          console.error(err)
          return
        }
        res.send(file_content);
      })
    
})

app.delete('/', function (req, res){
const content = req.body;
const key = +(Object.keys(content));
const array = fs.readFileSync("data.txt").toString().split("\n")

fs.writeFile('./data.txt', "", function (err) {
    if (err) throw err;
}); 
    array.forEach((element,index) => { if (index != array.length-1) {
        element += "\n";
        if(index != key-1) {
             fs.appendFile("./data.txt", element, function(error) {if(error) throw error} )
        }
   }})
    fs.readFile('./data.txt', 'utf8' , (err, file_content) => {
        if (err) {
          console.error(err)
          return
        }
        res.send(file_content);
      })
})

app.listen(8080)

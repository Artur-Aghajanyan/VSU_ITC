const swaggerUi = require('swagger-ui-express');
const swaggerDocument = require('./swagger.json');
const cors = require('cors');

var express = require('express');
var app = express();

app.get('/users', (req, res) => {
    res.send({
        id: "1",
        email: "u1@s.com",
	lastName: "Stepanyan",
	firstName: "Lusine"
    });
})

app.delete('/users', (req, res) => {
    res.send({
        id: "2",
        email: "u2@s.com",
	lastName: "Harutyunyan",
	firstName: "Eliza"
    });
})

app.put('/admin', (req, res) => {
    res.send({
        id: "1",
        email: "ad1@s.com",
	lastName: "Margaryan",
	firstName: "Lyudvik"
    });
})

app.delete('/admin', (req, res) => {
    res.send({
        id: "2",
        email: "ad2@s.com",
	lastName: "Amirxanyan",
	firstName: "Norayr"
    });
})

app.get('/author', (req, res) => {
    res.send({
	lastName: "Rick",
	firstName: "Riordan",
	book: "Percy Jackson and the Olympians"
    });
})

app.post('/author', (req, res) => {
    res.send({
        lastName: "Ayn",
	firstName: "Rand",
	book: "Atlas Shrugged"
    });
})

app.post('/book', (req, res) => {
    res.send({
        name: "Daniel Keyes",
	book: "The Minds of Billy Milligan"
    });
})

app.put('/book', (req, res) => {
    res.send({
        name: "Henry Rider Haggard",
	book: "Montezuma's Daughter"
    });
})

app.use('/api-docs', swaggerUi.serve, swaggerUi.setup(swaggerDocument));
app.use(cors());

app.listen(8083);

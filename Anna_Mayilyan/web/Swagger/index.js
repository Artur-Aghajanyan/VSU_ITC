const swaggerUi = require('swagger-ui-express');
const swaggerDocument = require('./swagger.json');

var express = require('express');
var app = express();

app.get('/senior', (req, res) => {
    res.send({
		id: 2,
        lastName: "Walker",
        firstName: "John"
    });

});

app.delete('/senior', (req, res) => {
    res.send({
        id: 3,
	lastName: "Myers",
	firstName: "Mike"
    });
});
app.put('/middle', (req, res) => {
    res.send({
        id: 4,
	lastName: "Brown",
	firstName: "Tom"
    });
});
app.delete('/middle', (req, res) => {
    res.send({
        id: 5,
	lastName: "Styles",
	firstName: "Tomas"
    });
});
app.get('/junior', (req, res) => {
    res.send({
	id: 4,
	lastName: "Herron",
	firstName: "Mary",
    });
});
app.post('/junior', (req, res) => {
    res.send({
	id: 5,
        lastName: "Brown",
	firstName: "Jonas",
    });
});
app.post('/intern', (req, res) => {
    res.send({
	id: 7,
        firstName: "Kate",
	lastName: "Rolling"
    });
});
app.put('/intern', (req, res) => {
    res.send({
	id: 3,
        firstName: "Mike",
	lastName: "Brown"
    });
});
app.use('/api-docs', swaggerUi.serve, swaggerUi.setup(swaggerDocument));
app.listen(3000);




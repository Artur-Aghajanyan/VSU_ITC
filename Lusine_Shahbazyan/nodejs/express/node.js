const express = require('express');
const app = express();
const swaggerUI = require('swagger-ui-express');
const swaggerDocument = require('./swagger.json');
const cors = require('cors');

app.get('/users', (req, res) => {
    res.send({
        id: "1"
    });
});

app.post('/users', (req, res) => {
    res.send('Post method for users');
});

app.delete('/admin', (req, res) => {
    res.send('Delete method for admin');
});

app.get('/admin', (req, res) => {
    res.send({
        id: "1",
        firstName: "Mery",
        lastName: "Pogosyan"
    });
});

app.post('/guests', (req, res) => {
    res.send('Post method for guests');
});

app.delete('/guests', (req, res) => {
    res.send('Delete method for guests');
});

app.put('/customers', (req, res) => {
    res.send('Put method for customers');
});

app.delete('/customers', (req, res) => {
    res.send('Delete method for customers');
});

app.use("/api-docs", swaggerUI.serve, swaggerUI.setup(swaggerDocument));
app.use(cors());
app.listen(8030);

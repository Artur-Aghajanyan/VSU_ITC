const express = require('express');
const cors = require('cors');
const swaggerUi = require('swagger-ui-express');
const swaggerDocument = require('./swagger.json');

const app = express();

const host = '127.0.0.1';
const port = 7000;
app.use(cors());
app.use('/api-docs', swaggerUi.serve, swaggerUi.setup(swaggerDocument));
app.get('/api/users', (req, res) => {
    if(req) {
        res.send('All ok, You can see all users');
    } else{
        res.end('I think something wrong ok');
    }
});
app.post('/api/post/user', (req, res) => {
    if(req) {
        res.send('All ok, Added new User');
    } else{
        res.end('I think something wrong ok');
    }
});

app.put('/api/put/car', (req, res) => {
    if(req) {
        res.send('All ok, Updated Car');
    } else{
        res.end('I think something wrong ok');
    }
});
app.delete('/api/delete/car', (req, res) => {
    if(req) {
        res.send('All ok, Deleted Car');
    } else{
        res.end('I think something wrong ok');
    }
});

app.put('/api/put/fruit', (req, res) => {
    if(req) {
        res.send('All ok, Updated fruit');
    } else{
        res.end('I think something wrong ok');
    }
});
app.delete('/api/delete/fruit', (req, res) => {
    if(req) {
        res.send('All ok, Deleted Car');
    } else{
        res.end('I think something wrong ok');
    }
});

app.put('/api/put/animal', (req, res) => {
    if(req) {
        res.send('All ok, Updated Animal');
    } else{
        res.end('I think something wrong ok');
    }
});
app.delete('/api/post/animal', (req, res) => {
    if(req) {
        res.send('All ok, Added new Animal');
    } else{
        res.end('I think something wrong ok');
    }
});

app.use((req, res) => {
    res.status(404).type('text/plain');
    res.send('Not found');
});

// eslint-disable-next-line no-console
app.listen(port, host, () => console.log(`Server listens http://${host}:${port}`));

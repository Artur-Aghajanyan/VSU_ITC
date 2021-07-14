const express = require('express');
const router = require('./Routes/router');
const cors = require('cors');
const swaggerUI = require('swagger-ui-express');
const swaggerDocument = require('./swagger.json');
const fs = require('fs');

const app = express();

fs.readFileSync("./DataBase/database.sql");

app.use(cors());
app.use('/api', swaggerUI.serve, swaggerUI.setup(swaggerDocument));
app.use('/', router);

app.listen(8080);
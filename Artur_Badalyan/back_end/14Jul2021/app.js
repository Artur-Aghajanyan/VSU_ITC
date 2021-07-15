const router = require('./routes/routes');
const swaggerUi = require('swagger-ui-express');
const cors = require('cors');
const swaggerDocument = require('./swagger.json');
const express = require('express');
const app = express();
const port = 5005;

app.use('/',router);
app.use(cors());

app.use('/api-docs',swaggerUi.serve,swaggerUi.setup(swaggerDocument));

// eslint-disable-next-line no-console
app.listen(port, () => console.log(`Example app listening at http://localhost:${port}`));
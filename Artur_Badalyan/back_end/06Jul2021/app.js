const router = require('./routes/routes')
const express =  require('express');
const app = express();
const port = 5005;

app.use('/',router)

app.listen(port, () => console.log(`Example app listening at http://localhost:${port}`));
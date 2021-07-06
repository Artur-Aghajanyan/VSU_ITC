const express = require('express');
const userRoutes = require('./routes/index');

const app = express();
app.use('/', userRoutes);
const port = process.env.port || 7000;

app.listen(port, () => console.log(`server running at port ${port}`));

module.exports = app;

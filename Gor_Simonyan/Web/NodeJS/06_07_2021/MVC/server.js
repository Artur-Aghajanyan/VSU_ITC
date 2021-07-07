const express = require('express')
const router = require('./Routes/router')

const app = express()

app.use('/', router)

app.listen(8081)
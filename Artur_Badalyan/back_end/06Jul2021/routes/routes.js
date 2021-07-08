const connection = require('../models/index');
const {checkID , checkData } = require('../middleware/middleware')
const controller = require('../controllers/controllers')
const express = require('express');
const bodyParser = require('body-parser');
const router = express();

router.use(bodyParser.json());

connection().then(() => {
    router.get('/', checkID, controller.requestGet)
    router.post('/post', checkData,controller.requestPost);
    router.delete('/delete', controller.requestDelete);
    router.put('/put', controller.requestPut);
});

module.exports = router;


const connection = require('../models/index');
const {checkID , checkData } = require('../middleware/middleware');
const controller = require('../controllers/controllers');
const express = require('express');
const bodyParser = require('body-parser');
const router = express();

router.use(bodyParser.json());

connection().then(() => {
    router.get('/users', checkID, controller.requestGet);
    router.post('/users', checkData,controller.requestPost);
    router.get('/admin', checkID, controller.requestGet);
    router.post('/admin', checkData,controller.requestPost);
    router.get('/products', checkID, controller.requestGet);
    router.post('/products', checkData,controller.requestPost);
    router.put('/products', controller.requestPut);
    router.delete('/products', controller.requestDelete);
    router.get('/company', checkID, controller.requestGet);
    router.post('/company', checkData,controller.requestPost);
    router.delete('/company', controller.requestDelete);
});

module.exports = router;


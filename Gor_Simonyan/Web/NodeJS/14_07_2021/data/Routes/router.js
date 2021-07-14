const express = require('express');
const func = require('../Controllers/controller');
const middle = require('../Middlewares/middleware');

const router = express.Router();

router.get('/users', middle.check, func.GetUsers);

router.post('/users', middle.check, func.PostUsers);

router.put('/users', middle.check, func.PutUsers);

router.delete('/users', middle.check, func.DeleteUsers);

router.get('/animals', middle.check, func.GetAnimals);

router.post('/animals', middle.check, func.PostAnimals);

router.put('/animals', middle.check, func.PutAnimals);

router.delete('/animals', middle.check, func.DeleteAnimals);

router.get('/cars', middle.check, func.GetCars);

router.post('/cars', middle.check, func.PostCars);

router.put('/cars', middle.check, func.PutCars);

router.delete('/cars', middle.check, func.DeleteCars);

router.get('/company', middle.check, func.GetCompany);

router.post('/company', middle.check, func.PostCompany);

router.put('/company', middle.check, func.PutCompany);

router.delete('/company', middle.check, func.DeleteCompany);

module.exports = router;
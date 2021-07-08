const express = require('express');
// const bodyParser = require('body-parser');
const userController = require('../controller/userController');
const middles = require('../middlewares/user');

const router = express.Router();
// router.use(bodyParser.json());

router.get('/', middles.checkID, userController.getUser);
router.post('/post', userController.postUser);
router.put('/put', middles.checkID, userController.putUser);
router.delete('/delete', middles.checkID, userController.deleteUser);
module.exports = router;

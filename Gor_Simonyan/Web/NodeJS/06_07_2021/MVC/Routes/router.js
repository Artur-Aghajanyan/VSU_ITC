const express = require('express')
const func = require('../Controllers/controller')
const middle = require('../Middlewares/middleware')

const router = express.Router()

router.get('/', middle.check, func.Get)

router.post('/', middle.check, func.Post)

router.put('/', middle.check, func.Put)

router.delete('/', middle.check, func.Delete)

module.exports = router
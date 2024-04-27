const express = require('express')
const Router = express.Router()

const { getHomepage } = require('../controllers/homeController')

Router.get('/', getHomepage)


module.exports = Router
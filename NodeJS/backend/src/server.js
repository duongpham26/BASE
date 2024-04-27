const express = require('express')
const path = require('path');
const dotenv = require('dotenv');
dotenv.config();

const configViewEngine = require('./config/configViewEngine')
const Router = require('./routes/web')

// import express from 'express' //lỗi


const app = express()
const port = process.env.PORT || 3001;
const hostname = process.env.HOST_NAME;

configViewEngine(app);

app.use(Router);

app.listen(port, () => {
  console.log(`Example app listening on port ${port}`)
})
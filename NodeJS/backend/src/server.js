const express = require('express')
const path = require('path');
// import express from 'express' //lỗi

const app = express()
const port = 3000

//config template engine
console.log("path: ",);
app.set('views', path.join(__dirname, 'views'))
app.set('view engine', 'ejs')

app.get('/', (req, res) => {
  res.render('demo.ejs')
})

app.listen(port, () => {
  console.log(`Example app listening on port ${port}`)
})
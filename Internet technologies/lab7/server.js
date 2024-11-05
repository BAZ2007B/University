const fs = require('fs');
var Mustache = require('mustache');
const express = require("express");


const app = express();
app.use(express.static('public'));
app.use(express.json())
app.use(express.urlencoded({extended: true}))

const host = 'localhost'
const port = 3000

app.get('/', (request, response) => {
  response.sendFile(__dirname + "/index.html");
});

app.get('/page1', (request, response) => {
  let data = JSON.parse(fs.readFileSync('page1.json'));
  let file = fs.readFileSync('template.html', "utf-8").toString();
  var template = Mustache.render(file, data);
  
  response.send(template);
});

app.get('/page2', (request, response) => {
  let data = JSON.parse(fs.readFileSync('page2.json'));
  let file = fs.readFileSync('template.html', "utf-8").toString();
  var template = Mustache.render(file, data);
  
  response.send(template);
});

app.get('/page3', (request, response) => {
  let data = JSON.parse(fs.readFileSync('page3.json'));
  let file = fs.readFileSync('template.html', "utf-8").toString();
  var template = Mustache.render(file, data);
  
  response.send(template);
});

app.get('/page4', (request, response) => {
  let data = JSON.parse(fs.readFileSync('page4.json'));
  let file = fs.readFileSync('template.html', "utf-8").toString();
  var template = Mustache.render(file, data);
  
  response.send(template);
});

app.get('/page5', (request, response) => {
  let data = JSON.parse(fs.readFileSync('page5.json'));
  let file = fs.readFileSync('template.html', "utf-8").toString();
  var template = Mustache.render(file, data);
  
  response.send(template);
});

app.post('/data', (request, response) => {

  let username = request.body.username;
  let firstCheckBoxDefault = request.body.firstDefault;
  let secondCheckBoxDefault = request.body.secondDefault;

  response.send(request.body)
});

app.listen(port, host, () =>
{
    console.log(`Listening on http://${host}:${port}`);
});
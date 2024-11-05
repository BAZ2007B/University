
const cors = require('cors');
const express = require("express");
const MongoClient = require("mongodb").MongoClient;
const objectId = require("mongodb").ObjectID;

const app = express();
const jsonParser = express.json();

const mongoClient = new MongoClient("mongodb://localhost:27017/", { useNewUrlParser: true });

let dbClient;

app.use(express.static(__dirname + "/public"));

mongoClient.connect(function (err, client) {
    if (err) return console.log(err);
    dbClient = client;
    app.locals.collection = client.db("adsdb").collection("ads");
    app.listen(3000, function () {
        console.log("Сервер ожидает подключения http://localhost:3000/");
    });
});

app.get("/api/ads", function (req, res) {

    const collection = req.app.locals.collection;
    collection.find({}).toArray(function (err, ads) {

        if (err) return console.log(err);
        res.send(ads)
    });

});

app.use(cors({
    origin: 'http://localhost:3000'
}));


// Удаление объявления
app.delete("/api/ads/:id", function (req, res) {
    const collection = req.app.locals.collection;
    const id = new objectId(req.params.id);
    collection.deleteOne({ _id: id }, function (err, result) {
        if (err) return console.log(err);
        res.send(result);
    });
});

app.post("/api/ads", jsonParser, function(req, res) {
    const collection = req.app.locals.collection;
    const ad = req.body;
    collection.insertOne(ad, function(err, result) {
      if (err) return console.log(err);
      res.send(result.ops[0]);
    });
  });

// прослушиваем прерывание работы программы (ctrl-c)
process.on("SIGINT", () => {
    dbClient.close();
    process.exit();
});
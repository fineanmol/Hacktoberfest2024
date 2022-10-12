const mongo = require('mongodb')
const MongoClient = require('mongodb').MongoClient;
const url ="mongodb://localhost:8080/mydb"


MongoClient.connect(url, function(err, db) {
    if (err) throw err;
    console.log("Database created!");
    db.close();
  });
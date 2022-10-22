const { response } = require("express");
const express = require("express");
const https = require("https");
const bodyParser = require("body-parser");

const app = express();

app.use(bodyParser.urlencoded({extended: true}));

app.get("/", function(req , res){
    res.sendFile(__dirname + "/index.html");
});

app.post("/", function(req , res){
    console.log(req.body.cityName);
    const query = req.body.cityName;
    const appkey = "9c74e1b1db429c43534ec3758be12f9b";
    const unit = "metric";
    const url = "https://api.openweathermap.org/data/2.5/weather?q=" + query + "&appid=" + appkey +"&units=" + unit ;
    https.get(url, function(response){
        console.log(response.statusCode);

        response.on("data", function(data){
            const weatherData = JSON.parse(data)
            const temp = weatherData.main.temp;
            const weatherDescription = weatherData.weather[0].description
            const icon = weatherData.weather[0].icon
            const imageURL = "https://openweathermap.org/img/wn/" + icon +"@2x.png"
            res.write("<h1>The temperture in "+ query +" is " + temp + " Degree Celcius</h1>");
            res.write("<h3>The weather is currently " + weatherDescription+ " </h3>");
            res.write("<img src=" + imageURL + ">");
            res.send();
        } )
    });
});






app.listen(3000 , function(){
    console.log("Server is runing on port 3000.");
})
// jshint esversion:6
const express = require("express");
const bodyParser = require("body-parser");
const https = require("https");
const { response } = require("express");

const app = express();

app.use(express.static("public"));
app.use(bodyParser.urlencoded({ extended: true }));

const port = process.env.PORT;

const localPort = 3000;



app.get("/",
    function (req, res) {
        res.sendFile(__dirname + "/signup.html");
    });



app.post("/", function (req, res) {
    const firstName = req.body.fName;
    const lastName = req.body.lName;
    const email = req.body.email;
    // console.log( firstName, lastName, email);

    const data = {
        members: [
            {
                email_address: email,
                status: "subscribed",
                merge_fields: {
                    FNAME: firstName,
                    LNAME: lastName
                }
            }
        ]
    };

    const jsonData = JSON.stringify(data);

    const url = 'https://us8.api.mailchimp.com/3.0/lists/829e931404';

    const options = {
        method: "POST",
        auth: "subha1:7c5bc28eb62f0f87f15cf8ed2870dc80-us8"
    };

    const request = https.request(url, options,
        function (response) {
            console.log("The status code: " + res.statusCode);
            if (res.statusCode === 200) {
                res.sendFile(__dirname + "/success.html");
            } else {
                res.sendFile(__dirname + "/failure.html");
            }
            response.on("data", function (data) {
                console.log(JSON.parse(data));
            });
        });


    request.write(jsonData);
    request.end();
});

app.post("/failure", function (req, res) {
    res.redirect("/");
});

app.listen(port || localPort,
    function () {
        console.log("Server is running on port " + port);
    });

// API key 
// 7c5bc28eb62f0f87f15cf8ed2870dc80-us8

// List Id :
// 829e931404
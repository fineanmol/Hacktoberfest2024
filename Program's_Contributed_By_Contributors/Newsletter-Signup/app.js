// jshint esversion:6
const express = require("express");


//add data base moongose
const db = require("./config/mongoose");
//add models
const admin = require("./models/email");
const bodyParser = require("body-parser");
const https = require("https");
const { response } = require("express");
const path = require("path");
const { render } = require("ejs");

const app = express();

app.use(express.static("public"));
app.use(bodyParser.urlencoded({ extended: true }));

//set ejs and view engine
app.set("view engine", "ejs");
//set views folder  path
app.set("views", path.join(__dirname, "views"));

const port = process.env.PORT;

const localPort = 3000;



app.get("/",
    function (req, res) {
        res.sendFile(__dirname + "/signup.html");
    });



app.post("/", async (req, res)=> {
     req.body.email;
     let obj=[];
     let user1= await admin.find({email:req.body.email});
      console.log(user1.length);
    //  //if user exit already
     if(user1.length!=0){
        return res.render("already");
     }
    
    //if user not exit 
    
    //  console.log(`user exit ${user1}`);
    
     else {
    admin.create({
        email:req.body.email,
        FirstName:req.body.fName,
        LastName:req.body.lName
      });
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
                // res.sendFile(__dirname + "/success.html");
                return res.render("success",{name:firstName});
            } else {
                res.sendFile(__dirname + "/failure.html");
                res.end();
            }
            response.on("data", function (data) {
                console.log(JSON.parse(data));
            });
        });

        request.write(jsonData);
        request.end();
    }

    
    
});

app.post("/failure", function (req, res) {
    res.redirect("/");
});

// app.listen(port || localPort,
//     function () {
//         console.log("Server is running on port " + port);
//     });

app.listen(8000);

// API key 
// 7c5bc28eb62f0f87f15cf8ed2870dc80-us8

// List Id :
// 829e931404
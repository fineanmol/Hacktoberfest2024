var cont = document.querySelector(".container");
var img = document.getElementById("newsimg");
var para = document.querySelector(".para");
var tit = document.querySelector(".tit");
var nexbtn = document.querySelector(".nextbtn");
var txt = '';
var inp = document.getElementById("topicinp");
var btn = document.querySelector(".submit");
var search = prompt("Enter the value, you want to search news for");
console.log(search);
var date = document.querySelector(".date")


var Apikey = "5d940e457fdb4997a19b0c561af7eb88";
var url = `https://newsapi.org/v2/everything?q=${search}&apiKey=${Apikey}`;
function getdata(){
    fetch(url).then((response)=>{
        return response.json();
    }).then((data)=>{
        // for(var i = 1;i < data.articles.length;){
            var i = 0;
            var newsimg = data.articles[i].urlToImage;
                var title = data.articles[i].title;
                var desc = data.articles[i].description;
                var datejson = data.articles[i].publishedAt;
                img.setAttribute("src",newsimg);
                para.innerHTML = desc;
                tit.innerHTML = title;
                date.innerHTML = datejson;
                // console.log(i);
            nexbtn.addEventListener("click",()=>{
                // console.log("Clicked");
                i+=1;
                var newsimg = data.articles[i].urlToImage;
                var title = data.articles[i].title;
                var desc = data.articles[i].description;
                img.setAttribute("src",newsimg);
                para.innerHTML = desc;
                tit.innerHTML = title;
                console.log(i);
               
            })

        // }
    });
    // console.log(inp.innerHTML);
    
};
getdata();


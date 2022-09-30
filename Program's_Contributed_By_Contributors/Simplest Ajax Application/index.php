<!-- 
    Write a simple AJAX script which takes input from an HTML form and makes a POST
request to a backend script. The backend script should return back the data which will be displayed
below the HTML form inside a ‘div’.
 -->

 <!DOCTYPE html>
 <html lang="en">
 <head>
    <title>AJAX</title>
 </head>
 <body>
    <form action="" method="post" onsubmit="add(event)">
        <input type="text" id="topic"><br>
        <input type="text" id="description"><br>
        <input type="submit" value="add and show">
    </form>

    <div id="data"></div>

    <script>
        function add(e){
            // prevent refreshing upon clickig the submit btn
            e.preventDefault();

            // get the data from form
            let topic = document.getElementById("topic").value;
            let description = document.getElementById("description").value;
            // encode the data
            let data = "topic=" + encodeURI(topic) + "&description=" + encodeURI(description);

            // create the XHR object
            let xhttp = new XMLHttpRequest();

            // send data to server
            xhttp.open("POST", "backend.php", true);
            xhttp.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
            xhttp.send(data);

            // will run everytime the readystate property changes
            xhttp.onreadystatechange = function(){
                // response
                if(this.readyState == 4 && this.status == 200){
                    document.getElementById("data").innerHTML = this.responseText;
                }
            }
        }

    </script>
 </body>
 </html>
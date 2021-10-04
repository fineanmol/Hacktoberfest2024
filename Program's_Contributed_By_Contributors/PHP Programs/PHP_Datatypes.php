<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>PHP Language Datatypes</title>
</head>
<style>
.container_head {
      max-width: 50%;
      background-color: rgb(108, 102, 189);
      border-radius: 10pt;
      padding: 02%;
      margin-top: 5pt;
      margin: auto;
    }

    .container_body {
      max-width: 50%;
      background-color: rgb(255, 255, 255);
      border-bottom-left-radius: 10px;
      border-bottom-right-radius: 10px;
      padding: 02%;
      margin-top: 5pt;
      margin: auto;
    }
    .heading {
      font-family: "Times New Roman", Times, serif;
      font-style: italic;
      text-align: center;
      color: whitesmoke;
    }
</style>
<body>

<div class="container_head">
      <h1 class="heading">PHP Datatypes</h1>
    </div>

    <div class="container_body">
    <?php

        echo"<h3>1. String  </h3>";
        $var="This is String Variable ";
        echo var_dump($var);
        echo "<br>";
        echo "<br>";
        //String 

        $var=89;
        echo"<h3>2. Integer </h3>";
        echo"The 89 is : ";
        echo var_dump($var);
        echo "<br>";
        echo "<br>";
        //Integer

        $var=9.90;
        echo"<h3>3. Float </h3>";
        echo"The 9.90 is : ";   
        echo var_dump($var);
        echo "<br>";
        echo "<br>";
        //float

        $var=true;  
        echo"<h3>4. Boolean </h3>";
        echo"The true is : ";
        echo var_dump($var);
        echo "<br>";
        echo "<br>";
        //boolean

        $cars = array("Volvo","BMW","Toyota");
        echo"<h3>5. Array </h3>";
        echo"The Car Names is : ";  
        var_dump($cars);

    ?>  

    </div>
    
</body>
</html>
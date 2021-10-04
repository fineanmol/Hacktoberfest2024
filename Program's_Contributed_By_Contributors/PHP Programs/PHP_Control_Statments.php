<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>PHP Control Statments</title>
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
      <h1 class="heading">PHP Control Statments</h1>
    </div>
    

    <div class="container_body">
      <h2>1. If Else Statments</h2>

      <?php

        $age=16;

        echo"<h3>The age is 16</h3>";

        if($age>18)
        {   
            echo"<h3>Good, Your are Above 18.</h3><br>";
        }
        else
        {
            echo"<h3>Opps, Your are Below 18.</h3>";
        }

        echo"<h2>2. Switch Statments</h2>";

        echo"<h3>Now the age is 28</h3>";

        $age=28;
        switch($age)
        {
            case 28:
                echo"<h3>The age is Above 18.</h3>";
                break;

            case 12:
                echo"<h3>The age is Below 18.</h3>";
                break;

            case 10:
                echo"<h3>The age is Near to 18.</h3>";
                break;
            
            default:
                echo"<h3>The age is Not Here.</h3>";

        }
        echo"<h2>3. While Loop</h2>";
        $x = 0;
        while($x <= 5) 
        {
            echo "<h4>While loop number is: $x.</h4>";
            $x++;
        }

        echo"<h2>4. For Loop</h2>";
        for($y=0;$y<=5;$y++)
        {
            echo "<h4>For loop number is: $y.</h4>";
        }

        echo"<h2>5. For Each Loop</h2>";

        $array_color=array("Red","Green","Blue","White","Black");

        foreach($array_color as $val)
        {
            echo"<h4>The array Value has: $val.</h4>";
        }

        echo"<h2>6. Do While Loop</h2>";
        $z=0;
        do
        {
            echo "<h4>Do While loop number is: $z.</h4>";
            $z++;
        }while($z<=5)

        
        

        ?>
    </div>
  </body>
</html>

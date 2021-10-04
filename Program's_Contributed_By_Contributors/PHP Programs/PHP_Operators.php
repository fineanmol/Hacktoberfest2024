<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>PHP Language Operators</title>
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
        <h1></h1>
<body>
        <div class="container_head">
            <h1 class="heading">Operators in PHP</h1>
        </div>
    <div class="container_body">

    <?php
    
    echo nl2br("<h3>A. Arithmetic operators in PHP*</h3>");
    $a=10;
    $b=5;
    $var_add=$a+$b;
    echo nl2br("1. Addition of 10 and 5 is ");
    echo $var_add;

    $var_sub=$a-$b;
    echo nl2br("\n2. Subtraction of 10 and 5 is ");
    echo $var_sub;

    $var_mul=$a*$b;
    echo nl2br("\n3. Multiplication of 10 and 5 is ");
    echo $var_mul;

    $var_divi=$a/$b;
    echo nl2br("\n4. Division of 10 and 5 is ");
    echo $var_divi;

    $var_mod= 10 % 6;
    echo nl2br("\n5. Modulus or Reminder of 10 on 6 is ");
    echo $var_mod;

    $var_expo = $a**$b;
    echo nl2br("\n6. Exponentiation of 10 on 5 is ");
    echo $var_expo;


    echo nl2br("\n\n<h3>B. Assignment operators in PHP*</h3>");

    $x = 20;  
    $x += 100;
    echo"1. Addition with = $x";

    echo"<br>";
    $x -= 100;
    echo"2. Subtraction with = $x";

    echo"<br>";
    $x *= 100;
    echo"3. Multiplication with = $x";

    echo"<br>";
    $x /= 100;
    echo"4. Division with = $x";

    echo"<br>";
    $x %= 100;
    echo"5. Modulus with = $x";

    echo"<br>";
    $x **= 10;
    echo"6. Exponentiation with = $x";

    echo nl2br("\n\n<h3>C. Comparison Operators in PHP*</h3>");

    echo("1. The Value 1 == 4 is ");
    echo var_dump(1==4);
    echo"<br>";

    echo("2. The Value 4 === 4 is ");
    echo var_dump(4===4);
    echo"<br>";
    
    echo("3. The Value 1 != 4 is ");
    echo var_dump(1!=4);
    echo"<br>";

    echo("4. The Value 1 <> 4 is ");
    echo var_dump(1<>4);
    echo"<br>";

    echo("5. The Value 1 !== 4 is ");
    echo var_dump(1!==4);
    echo"<br>";

    echo("6. The Value 1 < 4 is ");
    echo var_dump(1<4);
    echo"<br>";

    echo("7. The Value 1 > 4 is ");
    echo var_dump(1>4);
    echo"<br>";

    echo("8. The Value 1 <= 4 is ");
    echo var_dump(1<=4);
    echo"<br>";

    echo("9. The Value 1 >= 4 is ");
    echo var_dump(1>=4);
    echo"<br>";

    $x = 5;  
    $y = 10;
    
    echo("10.1 The Values of 5 <=> 10 ");
    echo var_dump($x <=> $y); // returns -1 because $x is less than $y
    echo "<br>";
    
    $x = 10;  
    $y = 10;
    
    echo("10.2 The Values of 10 <=> 10 ");
    echo var_dump($x <=> $y); // returns 0 because values are equal
    echo "<br>";
    
    $x = 15;  
    $y = 10;

    echo("10.2 The Values of 15 <=> 10 ");
    echo var_dump($x <=> $y); // returns +1 because $x is greater than $y
    echo "<br>";
    
    echo nl2br("\n<h3>D. Increment / Decrement Operators in PHP*</h3>");

    $x = 15;  
    echo"1. Pre Incerment ++varible ";
    echo ++$x;
    echo"<br>";


    $x = 15;  
    echo"2. Pre Decerment --varible ";
    echo --$x;
    echo"<br>";

    $x = 15;  
    echo"3. Post Incerment varible++ ";
    echo $x++;
    echo", After Incerment $x";
    echo"<br>";

    $x = 15;  
    echo"4. Post Decerment varible-- ";
    echo $x--;
    echo", After Decerment $x";
   

    echo nl2br("\n\n<h3>E. Logical Operators in PHP*</h3>");

    $var_a=(true and true);
    echo"1. true and true = ";
    echo var_dump($var_a);
    echo"<br>";

    $var_a=(true or false);
    echo"2. true or false = ";
    echo var_dump($var_a);
    echo"<br>";

    $var_a=(true && false);
    echo"3. true && false = ";
    echo var_dump($var_a);
    echo"<br>";

    $var_a=(false || false);
    echo"4. false || false = ";
    echo var_dump($var_a);
    echo"<br>";

    $var_a=(false xor false);
    echo"5. false xor false = ";
    echo var_dump($var_a);
    echo"<br>";

    $var_a=(false xor true);
    echo"6. false xor true = ";
    echo var_dump($var_a);
    echo"<br>";

    ?> 

    </div>

</body>

</html>
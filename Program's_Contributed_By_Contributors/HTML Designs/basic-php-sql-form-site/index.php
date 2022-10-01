<?php
$insert= FALSE;
if(isset($_POST['name'])){
 
  $server="localhost";
  $username="root";
  $password="";
  $dbname= "us_trip";

  $con= mysqli_connect($server, $username, $password, $dbname);

  if(!$con){
    die("connnection to the database failed due to ".mysqli_connect_error());
  }

 

  $name= $_POST['name'];
  $class= $_POST['class'];
  $gender= $_POST['gender'];
  $email= $_POST['email'];
 
  $phone= $_POST['phone'];
  $other= $_POST['other'];

 $sql= "INSERT INTO `us_trip`.`trip` ( `name`, `class`, `gender`, `email`, `phone`, `other`, `dt`) VALUES ('$name', '$class', '$gender', '$email', '$phone', '$other', current_timestamp())";
//  echo $sql;

 if($con->query($sql)==TRUE){
    // echo "successfully inserted";
    $insert= true;
 }
 else{
    echo "ERROR: $sql <br> $con->error";
    
 }

 $con->close();

}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="style.css?v=<?php echo time(); ?>">
    <link rel="preconnect" href="https://fonts.googleapis.com">
<link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
<link href="https://fonts.googleapis.com/css2?family=Poppins&display=swap" rel="stylesheet">
    <title>Welcome to travel form</title>
</head>
<body>
    <img src="Gndec19.jpg" alt="image">
    <div class="container">
        <h3> Welcome to GNDEC US trip form</h3>
        <p>Enter your details and submit the form to confirm your participation in the trip</p>


        <?php
        if($insert==true){
        
       echo  "<p class='alerttext'>Thanks for submitting the form. We are happy for your joining in US trip</p>";
        }
     ?>
        

        <form action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>" method="post">
            <input type="text" name="name" id="name" placeholder="Enter your name">
            <input type="text" name="class" id="class" placeholder="Enter your class">
            <input type="text" name="gender" id="gender" placeholder="Enter your gender">
            <input type="email" name="email" id="email" placeholder="Enter your email">
            <input type="phone" name="phone" id="phone" placeholder="Enter your phone">
            <textarea name="other" id="other" cols="40" rows="10">Enter any information here...</textarea>
            <button class="btn">Submit</button>
           
        </form>

    </div>

    <footer>
    &copy; created by chetan &hearts;
    </footer>
    <script src="index.js"></script>
    
   
</body>
</html>

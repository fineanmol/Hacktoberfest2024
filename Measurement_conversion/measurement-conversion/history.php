<html>
<!DOCTYPE html>
<html>
  <head>
    <meta charset="UTF-8">
    <title>Conversion History</title>
    <link href="styles.css" rel="stylesheet" type="text/css">
  </head>
<?php
$servername="localhost";
$username="root";
$password="";
$database="measurement-conversion";
$conn=mysqli_connect($servername,$username,$password,$database);
if(!$conn)
{
	die("oops connection failed".mysqli_connect_error());
}
else
{
 echo "Great Your connection is successful";
}
?>
<h1 align="center">Your Conversion History</h1>
<table align="center" border="1" >
 <tr>
 <th>Sr No.</th><th>From Value</th><th>From Unit</th><th>To Value</th><th>To Unit</th><th>Date Time</th>
 </tr>
<?php
 $sql="SELECT * FROM `conversions` ";
 $result = mysqli_query($conn, $sql);
 $i=1;
 while($raw=mysqli_fetch_assoc($result))
 { 
 ?>
 <tr>
  <td><?php echo $i?></td>
  <td><?php echo $raw['from_value']?></td>
  <td><?php echo $raw['from_unit']?></td>
  <td><?php echo $raw['to_value']?></td>
  <td><?php echo $raw['to_unit']?></td>
  <td><?php echo $raw['dt']?></td>
 </tr>
 <?php
 $i++;}
 ?> 
</table>
<br />

  <p align="center">  <a href="index.php">Return to menu</a></p>

</html>
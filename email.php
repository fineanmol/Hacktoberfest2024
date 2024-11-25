<?php
if(isset($_POST['sendemail']))
{
$Name=$_POST['UserName'];
$Email=$_POST['UserEmail'];
$Message=$_POST['UserMessage'];
require 'email/PHPMailerAutoload.php';
$mail= new PHPMailer;
$mail->isSMTP();
$mail->Host='smtp.gmail.com';
$mail->Port=587;
$mail->SMTPAuth=true;
$mail->SMTPSecure='tls';

$mail->Username=''; // Sender Email
$mail->Password=''; //Sender Password

$mail->setFrom($Email);
$mail->addAddress(''); //Sender email address
$mail->addReplyTo(''); //reply to adress

$mail->isHTML(true);
$mail->Subject=('From PORTFOLIO');
$mail->Body=$Message;

if(!$mail->send())
{
	echo"<p class='errormsg'>Send Success</p>";	
}
else
{
	echo"<p class='errormsg'>Send success</p>";	
}
}
?>
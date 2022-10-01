<?php
// Initialize the session
session_start();

?>

<!DOCTYPE html>

<html lang="en">
    <head>
        <meta charset="UTF-8">
        <title>Home Page - Login</title>
        <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css">
        <style>
            body{ font: 14px sans-serif; }
            .wrapper{ width: 360px; padding: 20px; }
        </style>
    </head>
    <body>
        <?php
            if(!isset($_SESSION["loggedin"]) || $_SESSION["loggedin"] !== true) {
                echo "<h1>Please Login to the system <a href=\"login.php\" class=\"btn btn-primary\">Login</a>  </h1>";
            } else {
                echo "<h1>Welcome, {$_SESSION["username"]} ! <a href=\"logout.php\" class=\"btn btn-primary\">Logout</a> <a href=\"change-password.php\" class=\"btn btn-secondary\">Change Password</a> </h1>";
            }
        ?>
    </body>
</html>



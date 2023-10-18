<?php
// Function to validate email
function validateEmail($email) {
    return filter_var($email, FILTER_VALIDATE_EMAIL);
}

// Function to validate password (minimum length of 8 characters)
function validatePassword($password) {
    return strlen($password) >= 8;
}

// Function to sanitize input data
function sanitizeString($input) {
    return htmlspecialchars(strip_tags(trim($input)));
}

// Check if the form is submitted
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Get form data and sanitize it
    $name = sanitizeString($_POST["name"]);
    $email = sanitizeString($_POST["email"]);
    $password = sanitizeString($_POST["password"]);

    // Validate email and password
    if (validateEmail($email) && validatePassword($password)) {
        // Registration successful, do something with the data
        echo "Name: $name <br>";
        echo "Email: $email <br>";
        echo "Password: ******** <br>";
        echo "Registration successful!";
    } else {
        // Invalid email or password
        echo "Invalid email or password. Please try again.";
    }
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>User Registration</title>
</head>
<body>
    <h2>User Registration Form</h2>
    <form method="post" action="<?php echo $_SERVER["PHP_SELF"]; ?>">
        Name: <input type="text" name="name"><br>
        Email: <input type="text" name="email"><br>
        Password: <input type="password" name="password"><br>
        <input type="submit" value="Register">
    </form>
</body>
</html>

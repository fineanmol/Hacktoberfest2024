function validate()
{
    var username = document.getElementById('username').value
    var email = document.getElementById('email').value
    var password = document.getElementById('password').value
    var cpassword = document.getElementById('cpassword').value

    console.log(username)

    checkusername(username)
    checkemail(email)
    checkpassword(password)
    checkpasswordsmatch(password , cpassword)
}


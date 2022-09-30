<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html lang="en" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title>Teacher Login</title>
    <link rel="stylesheet" href="./CSS/style.css">
    
  </head>
  <body>
    <div class="center">
      <h1>Teacher Login</h1>
      <form method="post" action="tprocess.jsp">
        <div class="txt_field">
          <input type="text" name="tid" required>
          <span></span>
          <label>Teacher ID</label>
        </div>
        <div class="txt_field">
          <input type="password" name="temail" required>
          <span></span>
          <label>Password</label>
        </div>
        <div class="pass">Forgot Password?</div>
        <input type="submit" value="Login">
        <div class="remember">
          <input type="checkbox" name="remember"> Remember me
        </div>
      </form>
    </div>

  </body>
</html>

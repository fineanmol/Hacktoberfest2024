<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
          <%@ page import="java.sql.*" %>
    <%
    try{
    	Class.forName("com.mysql.cj.jdbc.Driver");
    }catch(Exception e)
    {
    	System.out.println(e);
    	e.printStackTrace();
    }
    %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Teacher Dashboard</title>
<link rel="stylesheet" href="./CSS/style.css">
</head>
<body>
<div class="w3-sidebar w3-bar-block w3-card w3-animate-left" style="display:none" id="mySidebar">
        <button class="w3-bar-item w3-button w3-large" onclick="w3_close()"> &times;</button>
        <center><img src="logo.png" height="100"></center><br>
        <a href="teacherdashboard.jsp" class="w3-bar-item w3-button"> Home</a>
        <a href="tassign.jsp" class="w3-bar-item w3-button">Assignnment</a>
        <a href="tpnotice.jsp" class="w3-bar-item w3-button">Principle Notice</a>
        <a href="facultylogin.jsp" class="w3-bar-item w3-button">Logout</a>
    </div>

    <div id="main">

        <div class="w3-teal">
            <button id="openNav" class="w3-button w3-teal w3-xlarge" onclick="w3_open()">&#9776;</button>
            <div class="w3-container">
                <h1>Siliguri Institute of Technology</h1>
            </div>
        </div>



        <div class="welcome">
            <div class="topnav">
                <a class="active">Welcome Teacher</a>
            </div>

        </div>
        <form method="post" action="tprocess2.jsp">
        <div class="giveass">
     			<center>
                <h5><label for="giveass"><u>Notice to Student</u> </label></h5>
                 <div>
                <textarea class="form-control" id="myTextar" name="tassign"></textarea>
  				<input type="submit" value="Send">
  				<output name="ptao"></output>
                </div>
                </div>
			 </form>
			</center>
        </div>
        </form>
        <div class="notification">
            <center>
                <h5><label for="notification"><u>Notifications:</u> </label><br><br></h5>
            </center>
            <p id="notification"></p>
        </div>

		<center>
			 <table class="table">
<tr>
<td scope="col">Notice</td>
</tr>
<%
try{
final String url = "jdbc:mysql://localhost/data";
final String user="root";
final String pass = "";
final String Query="select * from tassign";
Connection conn = DriverManager.getConnection(url,user,pass);
Statement st = conn.createStatement();
ResultSet rs = st.executeQuery(Query);
while(rs.next()){
	%>
<tr>
<td>Teacher To Student Assignment:-<%=rs.getString("tassign")%>
</tr>
<% 
}
}catch(Exception e)
{
System.out.println(e);
e.printStackTrace();
}
%>

</table>
</center>
    </div>
    <script>
        function myFunction() {
            var x = document.getElementById("myTextar").value;
            document.getElementById("notification").innerHTML = x;
        }

        function w3_open() {
            document.getElementById("main").style.marginLeft = "25%";
            document.getElementById("mySidebar").style.width = "25%";
            document.getElementById("mySidebar").style.display = "block";
            document.getElementById("openNav").style.display = 'none';
        }
        function w3_close() {
            document.getElementById("main").style.marginLeft = "0%";
            document.getElementById("mySidebar").style.display = "none";
            document.getElementById("openNav").style.display = "inline-block";
        }
    </script>


    <!-- Optional JavaScript; choose one of the two! -->

    <!-- Option 1: Bootstrap Bundle with Popper -->
    <!-- <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js"
        integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM"
        crossorigin="anonymous"></script> -->

    <!-- Option 2: Separate Popper and Bootstrap JS -->
    <!--
    <script src="https://cdn.jsdelivr.net/npm/@popperjs/core@2.9.2/dist/umd/popper.min.js" integrity="sha384-IQsoLXl5PILFhosVNubq5LC7Qb9DXgDA9i+tQ8Zj3iwWAwPtgFTxbJ8NT4GN1R8p" crossorigin="anonymous"></script>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.min.js" integrity="sha384-cVKIPhGWiC2Al4u+LWgxfKTRIcfu0JTxR+EQDz/bgldoEyl4H0zUF0QKbrJ0EcQF" crossorigin="anonymous"></script>
    -->
</body>
</html>
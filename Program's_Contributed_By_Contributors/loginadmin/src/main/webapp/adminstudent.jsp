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
<title>Student Details</title>
<link rel="stylesheet" href="./CSS/style.css">
</head>
<body>
        <div class="w3-sidebar w3-bar-block w3-card w3-animate-left" style="display:none" id="mySidebar">
        <button class="w3-bar-item w3-button w3-large" onclick="w3_close()"> &times;</button>
        <center><img src="logo.png" height="100"></center><br>
 		<a href="admindashboard.jsp" class="w3-bar-item w3-button"> Home</a>
        <a href="admincourse.jsp" class="w3-bar-item w3-button">Courses</a>
        <a href="adminstudent.jsp" class="w3-bar-item w3-button">Student</a>
        <a href="adminsubject.jsp" class="w3-bar-item w3-button">Subject</a>
        <a href="adminfaculty.jsp" class="w3-bar-item w3-button">Faculty</a>
     <a href="adminlogin.jsp" class="w3-bar-item w3-button">Logout</a>
    </div>

    <div id="main">

        <div class="w3-teal">
            <button id="openNav" class="w3-button w3-teal w3-xlarge" onclick="w3_open()">&#9776;</button>
            <div class="w3-container">
                <h1>Welcome To Siliguri Institute of Technology</h1>
            </div>
        </div>

		
        <div class="w3-container">
            <center><input type="submit" value="Add Student" onclick="openForm()"></center>
            <div class="form-popup" id="myForm">
              <form action="process3.jsp" method="post" class="form-container">
                
            
                <label for="fname"><b>First Name:</b></label>
                <input type="text"  placeholder="Enter Full Name" name="fname" required>
            
                <label for="lname"><b>Last name :</b></label>
                <input type="text" placeholder="Enter Last Name" name="lname" required>
            
                <label for="Roll"><b>Roll No :</b></label>
                <input type="text"  placeholder="Enter Roll Number" name="roll" required>
                
                <label for="course"><b>Course :</b></label>
                <input type="text"  placeholder="Enter Course" name="course" required>
                
                <label for="sem"><b>Year</b></label>
                <input type="text"  placeholder="Enter Year" name="year" required>


                


                <button type="submit" class="btn">Add</button>
                <button type="button" class="btn cancel" onclick="closeForm()">Close</button>
              </form>
            </div>
        </div>
        <div>
            <form action="#">
              <form class="example" action="action_page.php">
                <input type="text" name="search" placeholder="Search..">
              </form>
              </form>
        </div>
        <center>
        <table class="table">
<tr>
<th scope="col">First Name</th>
<th scope="col">Last Name</th>
<th scope="col">Roll</th>
<th scope="col">Course</th>
<th scope="col">Year</th>
<th scope="col">Edit</th>
<th scope="col">Delete</th>
</tr>
    <%
try{
final String url = "jdbc:mysql://localhost/data";
final String user="root";
final String pass = "";
final String Query="select * from student_details";
Connection conn = DriverManager.getConnection(url,user,pass);
Statement st = conn.createStatement();
ResultSet rs = st.executeQuery(Query);
while(rs.next()){
	%>
<tr>
<td><%=rs.getString("fname")%></td>
<td><%=rs.getString("lname")%></td>
<td><%=rs.getString("roll")%></td>
<td><%=rs.getString("course")%></td>
<td><%=rs.getString("year")%></td>
<form action="process3.jsp" method="post">
<td><a href="update.jsp?roll=<%=rs.getString("roll")%>">Edit</a></td>
<td><a href="delete.jsp?roll=<%=rs.getString("roll")%>">Delete</a></td>
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
    </div>
</center>
    <script>//for navbar
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
    <script>//for add button
      function openForm() {
        document.getElementById("myForm").style.display = "block";
      }
      
      function closeForm() {
        document.getElementById("myForm").style.display = "none";
      }
      </script>


    <!-- Optional JavaScript; choose one of the two! -->

    <!-- Option 1: Bootstrap Bundle with Popper -->
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js"
        integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM"
        crossorigin="anonymous"></script>

    <!-- Option 2: Separate Popper and Bootstrap JS -->
    <!--
    <script src="https://cdn.jsdelivr.net/npm/@popperjs/core@2.9.2/dist/umd/popper.min.js" integrity="sha384-IQsoLXl5PILFhosVNubq5LC7Qb9DXgDA9i+tQ8Zj3iwWAwPtgFTxbJ8NT4GN1R8p" crossorigin="anonymous"></script>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.min.js" integrity="sha384-cVKIPhGWiC2Al4u+LWgxfKTRIcfu0JTxR+EQDz/bgldoEyl4H0zUF0QKbrJ0EcQF" crossorigin="anonymous"></script>
    -->
    
</body>
</html>
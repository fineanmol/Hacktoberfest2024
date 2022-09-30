<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="java.sql.*"%>
<%
try{
	String lname = request.getParameter("lname");
	String roll = request.getParameter("roll");
	String redirectUrl = "studentdashboard.jsp";
	final String url="jdbc:mysql://localhost/data";
	final String user="root";
	final String pass="";
	final String Query="select * from student_details where lname='"+lname+"' and roll='"+roll+"'";
//this code is to register the mysql connector
Class.forName("com.mysql.cj.jdbc.Driver");
//this code is to establish the connection
Connection conn=DriverManager.getConnection(url,user,pass);
Statement st = conn.createStatement();
ResultSet rs = st.executeQuery(Query);
rs.next();
if(rs.getString("lname").equals(lname) && rs.getString("roll").equals(roll))
{
	response.sendRedirect(redirectUrl);
}
else
{
	out.println("Incorrect Login Details");
}
}catch(Exception e)
{
	System.out.println(e);
	e.printStackTrace();
}
%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="java.sql.*"%>
<%
try{
	String username = request.getParameter("username");
	String password = request.getParameter("password");
	String redirectUrl = "admindashboard.jsp";
	final String url="jdbc:mysql://localhost/data";
	final String user="root";
	final String pass="";
	final String Query="select * from adminlogin where username='"+username+"' and password='"+password+"'";
//this code is to register the mysql connector
Class.forName("com.mysql.cj.jdbc.Driver");
//this code is to establish the connection
Connection conn=DriverManager.getConnection(url,user,pass);
Statement st = conn.createStatement();
ResultSet rs = st.executeQuery(Query);
rs.next();
if(rs.getString("username").equals(username) && rs.getString("password").equals(password))
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
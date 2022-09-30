<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="java.sql.*"%>
<% 
try{
	String tassign = request.getParameter("tassign");
	String redirectUrl = "tassign.jsp";
	final String url="jdbc:mysql://localhost/data";
	final String user="root";
	final String pass="";
	final String Query="insert into tassign(tassign) values(?)";
//this code is to register the mysql connector
Class.forName("com.mysql.cj.jdbc.Driver");
//this code is to establish the connection
Connection conn=DriverManager.getConnection(url,user,pass);
PreparedStatement pst = conn.prepareStatement(Query);
pst.setString(1, tassign);
pst.executeUpdate();
response.sendRedirect(redirectUrl);
}catch(Exception e)
{
	System.out.println(e);
	e.printStackTrace();
}
%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="java.sql.*"%>
<% 
try{
	String scode = request.getParameter("scode");
	String sname = request.getParameter("sname");
	String course_name = request.getParameter("course_name");
	String tmarks = request.getParameter("tmarks");
	String pmark = request.getParameter("pmark");
	String redirectUrl = "adminsubject.jsp";
	final String url="jdbc:mysql://localhost/data";
	final String user="root";
	final String pass="";
	final String Query="insert into subject(scode,sname,course_name,tmarks,pmark) values(?,?,?,?,?)";
//this code is to register the mysql connector
Class.forName("com.mysql.cj.jdbc.Driver");
//this code is to establish the connection
Connection conn=DriverManager.getConnection(url,user,pass);
PreparedStatement pst = conn.prepareStatement(Query);
pst.setString(1, scode);
pst.setString(2, sname);
pst.setString(3, course_name);
pst.setString(4, tmarks);
pst.setString(5, pmark);
pst.executeUpdate();
response.sendRedirect(redirectUrl);
}catch(Exception e)
{
	System.out.println(e);
	e.printStackTrace();
}
%>
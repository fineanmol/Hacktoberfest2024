<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="java.sql.*"%>
<% 
try{
	String tid = request.getParameter("tid");
	String tname = request.getParameter("tname");
	String qual = request.getParameter("qual");
	String temail = request.getParameter("temail");
	String sub = request.getParameter("sub");
	String redirectUrl = "adminfaculty.jsp";
	final String url="jdbc:mysql://localhost/data";
	final String user="root";
	final String pass="";
	final String Query="insert into faculty_details(tid,tname,qual,temail,sub) values(?,?,?,?,?)";
//this code is to register the mysql connector
Class.forName("com.mysql.cj.jdbc.Driver");
//this code is to establish the connection
Connection conn=DriverManager.getConnection(url,user,pass);
PreparedStatement pst = conn.prepareStatement(Query);
pst.setString(1, tid);
pst.setString(2, tname);
pst.setString(3, qual);
pst.setString(4, temail);
pst.setString(5, sub);
pst.executeUpdate();
response.sendRedirect(redirectUrl);
}catch(Exception e)
{
	System.out.println(e);
	e.printStackTrace();
}
%>
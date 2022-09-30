<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
 pageEncoding="UTF-8"%>
<%@ page import="java.sql.*"%>
<%
try{
	String tid = request.getParameter("tid");
	String temail = request.getParameter("temail");
	String redirectUrl = "teacherdashboard.jsp";
	final String url="jdbc:mysql://localhost/data";
	final String user="root";
	final String pass="";
	final String Query="select * from faculty_details where tid='"+tid+"' and temail='"+temail+"'";
//this code is to register the mysql connector
Class.forName("com.mysql.cj.jdbc.Driver");
//this code is to establish the connection
Connection conn=DriverManager.getConnection(url,user,pass);
Statement st = conn.createStatement();
ResultSet rs = st.executeQuery(Query);
rs.next();
if(rs.getString("tid").equals(tid) && rs.getString("temail").equals(temail))
{
	response.sendRedirect(redirectUrl);
}
}catch(Exception e)
{
	System.out.println(e);
	e.printStackTrace();
}
%>
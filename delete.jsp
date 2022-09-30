<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@page import="java.sql.*" %>
<%
String redirectUrl = "adminstudent.jsp";
String roll = request.getParameter("roll");
final String url="jdbc:mysql://localhost/data";
final String user="root";
final String pass="";
//this code is to register the mysql connector
Class.forName("com.mysql.cj.jdbc.Driver");
//this code is to establish the connection
Connection conn=DriverManager.getConnection(url,user,pass);
Statement st = conn.createStatement();
st.executeUpdate("delete from student_details where roll='"+roll+"'");
response.sendRedirect(redirectUrl);
%>
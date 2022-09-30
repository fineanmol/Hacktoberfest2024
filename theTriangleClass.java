//The Triangle Class program by Mohammed Raiyyan Shaik
//Date: 11/11/2021
//NetID: mshai6
//UIN: 664370305

import java.util.*;

public class theTriangleClass{
	public static void main(String[] args){
		Triangle triangle = new Triangle(1, 1.5, 1);
		triangle.setColor("Yellow");
		triangle.setFilled(true);
		System.out.println(triangle);
		System.out.println("The area is "+ triangle.getArea());
		System.out.println("The perimeter is "+ triangle.getPerimeter());
		//System.out.println(triangle);
		System.out.println("Color is " + triangle.getColor());
		System.out.println("Filled is " + triangle.isFilled());
	}
}

class GeometricObject{
	private String color = "white";
    private boolean filled;
    private java.util.Date dateCreated;
	
	//Constructing a default geometric object
    public GeometricObject(){
		dateCreated = new java.util.Date();
    }
	
	//Constructing a geometric object with the specified color and filled value
    public GeometricObject(String color, boolean filled){
        dateCreated = new java.util.Date();
        this.color = color;
        this.filled = filled;
    }
    
	//Returning color
    public String getColor(){  
		return color;
    }
    
	//Setiting a new color
    public void setColor(String color){
		this.color = color;
    }
	
    //Returning filled. Since filled is boolean, it is the getter method is named isFilled 
    public boolean isFilled(){
        return filled;
    }
    
	//Setting a new filled
    public void setFilled(boolean filled){
        this.filled = filled;
    }
	
    //Getting dateCreated
    public java.util.Date getDateCreated(){
		return dateCreated;
    }
    
	//Returning a string representation of this object
    public String toString(){
        return "created on " + dateCreated + "\ncolor: " + color +" and filled: " + filled;
    }

}

class Triangle extends GeometricObject{
	private double side1;
	private double side2;
	private double side3;
	public Triangle(double side1, double side2, double side3){
		this.side1 = side1;
		this.side2 = side2;
		this.side3 = side3;
	}
	public Triangle(double side1, double side2, double side3, String color, boolean filled){
		this.side1 = side1;
		this.side2 = side2;
		this.side3 = side3;
		setColor(color);
		setFilled(filled);
	}
	public double getSide1(){
		return side1;
	}
	public void setSide1(double side1){
		this.side1 = side1;
	}
	public double getSide2(){
		return side1;
	}
	public void setSide2(double side2){
		this.side2 = side2;
	}
	public double getSide3(){
		return side3;
	}
	public void setSide3(double side3){
		this.side3 = side3;
	}
	public double getPerimeter(){
		double p = side1 + side2 + side3;
		return p;
	}
	public double getArea(){
		double s = (side1 + side2 + side3)/2.0;
		double area = Math.pow(s*(s - side1)*(s - side2)*(s - side3), 0.5);
		return area; 
	}
	public String toString(){
		return "Triangle: side1 = " + side1 + " side2 = " + side2 + " side3 = " + side3;
	}
}

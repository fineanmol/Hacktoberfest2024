/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package stack;

import java.util.Arrays;

/**
 *
 * @author Zohaib Hassan Soomro
 */
///////////Reverse Polish Notation   i.e 7 2 + 5 2- * = (7+2)*(5-2) 
public class RPN {

public RPN(String[] array) {
    Stack stack = new ArrayStack(array.length);
//    or 
// Stack stack = new LinkedStack();
    for (int i = 0; i < array.length; i++) {
        String input = array[i];
        if (isAnOperator(input)) {
            double lastElement = Double.parseDouble((String) stack.pop());
            double secondlastElement = Double.parseDouble((String) stack.pop());
            double result = evaluate(secondlastElement, lastElement, input);
            stack.push("" + result);
        } else {
            stack.push(input);
        }
    }
}
//DMAS= Division, Multiplication, Addition, Subtraction

/////checks if input is an operator
private boolean isAnOperator(String operator) {
    return (operator.length() == 1 && ("DMAS".indexOf(operator) >= 0 || "dmas".indexOf(operator) >= 0));
}

/////evaluates last two digits with corresponding operation
private double evaluate(double x, double y, String op) {
    double z = 0;
    switch (op) {
        case "a":
        case "A":
            z = x + y;
            break;
        case "s":
        case "S":
            z = x - y;
            break;

        case "m":
        case "M":
            z = x * y;
            break;

        case "d":
        case "D":
            z = x / y;
            break;
    }
    System.out.println(x + " " + op + " " + y + " = " + z);
    return z;
}

public static void main(String[] args) {
    String str = new String("7 2 s 5 8 4 D m 2 d D 2 a");  //works on both lowercase & uppercase//  (((7-2) / ((5*(8/4)) /2))+2)=3
    String[] array = str.split(" ");
    new RPN(array);
}
}

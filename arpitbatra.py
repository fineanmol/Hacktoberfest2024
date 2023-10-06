import java.awt.*;
import java.awt.event.*;

class Calculator extends Frame implements ActionListener {
private TextField tf;
private Button[] buttons;
private String[] buttonLabels = {
"7", "8", "9", "/",
"4", "5", "6", "*",
"1", "2", "3", "-",
"0", "C", "=", "+"
};

private String currentInput = "";
private String currentOperator = "";
private double result = 0.0;

public Calculator() {
  
setTitle("Simple Calculator");
setSize(300, 400);
setLayout(new BorderLayout());

tf = new TextField();
tf.setFont(new Font("Arial", Font.PLAIN, 24));
tf.setEditable(false);
add(tf, BorderLayout.NORTH);

Panel panel = new Panel();
panel.setLayout(new GridLayout(4, 4));

buttons = new Button[buttonLabels.length];
for (int i = 0; i < buttonLabels.length; i++) {
buttons[i] = new Button(buttonLabels[i]);
buttons[i].setFont(new Font("Arial", Font.PLAIN, 18));
buttons[i].addActionListener(this);
panel.add(buttons[i]);
}
add(panel, BorderLayout.CENTER);

addWindowListener(new WindowAdapter() {
public void windowClosing(WindowEvent we) {
System.exit(0);
}
});
}
public void actionPerformed(ActionEvent ae) {
String actionCommand = ae.getActionCommand();

if (actionCommand.equals("C")) {
currentInput = "";
currentOperator = "";
result = 0.0;
} else if (actionCommand.equals("=")) {
try {
double operand = Double.parseDouble(currentInput);
switch (currentOperator) {
case "+":
result += operand;
break;
case "-":
result -= operand;
break;
case "*":
result *= operand;
break;
case "/":
if (operand != 0) {
result /= operand;
} else {
currentInput = "Error";
result = 0.0;
}
break;
default:
result = operand;
}
currentInput = Double.toString(result);
} catch (NumberFormatException e) {
currentInput = "Error";
result = 0.0;
}
currentOperator = "";
} else {
currentInput += actionCommand;
if (actionCommand.equals("+") || actionCommand.equals("-") ||
actionCommand.equals("*") || actionCommand.equals("/")) {
currentOperator = actionCommand;
}
}
tf.setText(currentInput);
}
public static void main(String[] args) {
Calculator calculator = new Calculator();
calculator.setVisible(true);
}
}

// program created by arpitbatra01

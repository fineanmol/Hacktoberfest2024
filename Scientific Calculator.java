
// Import the Swing module and other necessary classes
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

// Define a ccdlass that extends JFrame and implements ActionListener
public class ScientificCalculator extends JFrame implements ActionListener {

    public static void main(String[] args) {
        // Create an instance of the ScientificCalculator class
        SwingUtilities.invokeLater(() -> {
            new ScientificCalculator();
        });
    }

    // Declare some constants for the font and the colors
    private static final Font BIGGER_FONT = new Font("monospaced", Font.PLAIN, 20);
    private static final Color DARK_GRAY = new Color(51, 51, 51);
    private static final Color LIGHT_GRAY = new Color(204, 204, 204);

    // Declare some variables for the components of the GUI
    private JTextField textField; // The text field to display the input and output
    private JButton[] numberButtons; // The buttons for the digits 0-9
    private JButton[] functionButtons; // The buttons for the functions sin, cos, log, etc.
    private JButton[] operatorButtons; // The buttons for the operators +, -, *, /, etc.
    private JButton clearButton; // The button to clear the text field
    private JButton equalButton; // The button to perform the calculation

    // Declare some variables for the logic of the calculator
    private boolean number = true; // A flag to indicate whether the next input is a number or not
    private String equalOp = "="; // A variable to store the current operator
    private CalculatorOp op = new CalculatorOp(); // An object of a helper class that performs the calculations

    // Define the constructor of the class
    public ScientificCalculator() {
        // Set the title, size, layout, and close operation of the frame
        super("Scientific Calculator");
        setSize(400, 500);
        setLayout(new BorderLayout());
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Create and configure the text field
        textField = new JTextField("", 12);
        textField.setHorizontalAlignment(JTextField.RIGHT);
        textField.setFont(BIGGER_FONT);
        textField.setEditable(false);
        textField.setBackground(Color.WHITE);

        // Create and configure the number buttons
        numberButtons = new JButton[10];
        for (int i = 0; i < 10; i++) {
            numberButtons[i] = new JButton(String.valueOf(i));
            numberButtons[i].setFont(BIGGER_FONT);
            numberButtons[i].setBackground(DARK_GRAY);
            numberButtons[i].setForeground(Color.WHITE);
            numberButtons[i].addActionListener(this); // Add this class as an action listener for each button
        }

        // Create and configure the function buttons
        functionButtons = new JButton[6];
        String[] functions = { "sin", "cos", "tan", "log", "sqrt", "pow" };
        for (int i = 0; i < 6; i++) {
            functionButtons[i] = new JButton(functions[i]);
            functionButtons[i].setFont(BIGGER_FONT);
            functionButtons[i].setBackground(LIGHT_GRAY);
            functionButtons[i].addActionListener(this); // Add this class as an action listener for each button
        }

        // Create and configure the operator buttons
        operatorButtons = new JButton[4];
        String[] operators = { "+", "-", "*", "/" };
        for (int i = 0; i < 4; i++) {
            operatorButtons[i] = new JButton(operators[i]);
            operatorButtons[i].setFont(BIGGER_FONT);
            operatorButtons[i].setBackground(LIGHT_GRAY);
            operatorButtons[i].addActionListener(this); // Add this class as an action listener for each button
        }

        // Create and configure the clear button
        clearButton = new JButton("C");
        clearButton.setFont(BIGGER_FONT);
        clearButton.setBackground(Color.RED);
        clearButton.setForeground(Color.WHITE);
        clearButton.addActionListener(this); // Add this class as an action listener for this button

        // Create and configure the equal button
        equalButton = new JButton("=");
        equalButton.setFont(BIGGER_FONT);
        equalButton.setBackground(Color.GREEN);
        equalButton.setForeground(Color.WHITE);
        equalButton.addActionListener(this); // Add this class as an action listener for this button

        // Create and add the panels for the buttons
        JPanel numberPanel = new JPanel();
        numberPanel.setLayout(new GridLayout(4, 3, 4, 4));
        for (int i = 1; i < 10; i++) {
            numberPanel.add(numberButtons[i]); // Add the number buttons from 1 to 9
        }
        numberPanel.add(numberButtons[0]); // Add the number button 0
        numberPanel.add(clearButton); // Add the clear button
        numberPanel.add(equalButton); // Add the equal button

        JPanel functionPanel = new JPanel();
        functionPanel.setLayout(new GridLayout(2, 3, 4, 4));
        for (int i = 0; i < 6; i++) {
            functionPanel.add(functionButtons[i]); // Add the function buttons
        }

        JPanel operatorPanel = new JPanel();
        operatorPanel.setLayout(new GridLayout(2, 2, 4, 4));
        for (int i = 0; i < 4; i++) {
            operatorPanel.add(operatorButtons[i]); // Add the operator buttons
        }

        // Add the text field and the panels to the frame
        add(textField, BorderLayout.NORTH);
        add(numberPanel, BorderLayout.CENTER);
        add(functionPanel, BorderLayout.WEST);
        add(operatorPanel, BorderLayout.EAST);

        // Make the frame visible
        setVisible(true);
    }

    // Define the method that handles the action events
    public void actionPerformed(ActionEvent e) {
        String displayText = textField.getText(); // Get the current text from the text field
        String command = e.getActionCommand(); // Get the command from the event source

        if (command.equals("C")) { // If the command is C, clear the text field and reset the variables
            textField.setText("");
            number = true;
            equalOp = "=";
            op.setTotal("");
        } else if (command.equals("=")) { // If the command is =, perform the calculation and display the result
            number = true;
            if (equalOp.equals("=")) {
                op.setTotal(displayText);
            } else if (equalOp.equals("+")) {
                op.add(displayText);
            } else if (equalOp.equals("-")) {
                op.subtract(displayText);
            } else if (equalOp.equals("*")) {
                op.multiply(displayText);
            } else if (equalOp.equals("/")) {
                op.divide(displayText);
            }
            textField.setText("" + op.getTotalString());
        } else if ("0123456789.".indexOf(command) >= 0) { // If the command is a digit or a decimal point, append it to
                                                          // the text field
            if (number) {
                textField.setText(command);
            } else {
                textField.setText(displayText + command);
            }
            number = false;
        } else { // If the command is a function or an operator, perform the corresponding
                 // operation and display the result
            number = true;
            if (command.equals("sin")) {
                textField.setText("" + Math.sin(Double.valueOf(displayText).doubleValue()));
            } else if (command.equals("cos")) {
                textField.setText("" + Math.cos(Double.valueOf(displayText).doubleValue()));
            } else if (command.equals("tan")) {
                textField.setText("" + Math.tan(Double.valueOf(displayText).doubleValue()));
            } else if (command.equals("log")) {
                textField.setText("" + Math.log(Double.valueOf(displayText).doubleValue()));
            } else if (command.equals("sqrt")) {
                textField.setText("" + Math.sqrt(Double.valueOf(displayText).doubleValue()));
            } else if (command.equals("pow")) {
                op.setTotal(displayText);
                equalOp = "^";
                textField.setText("");
            } else {
                if (equalOp.equals("=")) {
                    op.setTotal(displayText);
                } else if (equalOp.equals("+")) {
                    op.add(displayText);
                } else if (equalOp.equals("-")) {
                    op.subtract(displayText);
                } else if (equalOp.equals("*")) {
                    op.multiply(displayText);
                } else if (equalOp.equals("/")) {
                    op.divide(displayText);
                } else if (equalOp.equals("^")) {
                    op.power(displayText);
                }
                textField.setText("" + op.getTotalString());
                equalOp = command;
            }
        }
    }

    // Define a helper class that performs the calculations
    private class CalculatorOp {

        // Declare a variable to store the total value
        private double total;

        // Define a constructor that sets the total value to zero
        public CalculatorOp() {
            total = 0;
        }

        // Define a method that returns the total value as a string
        public String getTotalString() {
            return "" + total;
        }

        // Method to set the total value to a given string
        public void setTotal(String input) {
            total = Double.parseDouble(input);
        }

        // Method to perform addition
        public void add(String input) {
            total += Double.parseDouble(input);
        }

        // Method to perform subtraction
        public void subtract(String input) {
            total -= Double.parseDouble(input);
        }

        // Method to perform multiplication
        public void multiply(String input) {
            total *= Double.parseDouble(input);
        }

        // Method to perform division
        public void divide(String input) {
            double divisor = Double.parseDouble(input);
            if (divisor != 0) {
                total /= divisor;
            } else {
                // Handle division by zero error
                total = Double.NaN; // You can set an appropriate error value here
            }
        }

        // Method to perform exponentiation
        public void power(String input) {
            double exponent = Double.parseDouble(input);
            total = Math.pow(total, exponent);
        }
    }
}

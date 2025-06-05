import java.util.Stack;

public class PostfixCalculator {
    public static int evaluatePostfix(String expression) {
        Stack<Integer> stack = new Stack<>();

        for (int i = 0; i < expression.length(); i++) {
            char ch = expression.charAt(i);

            if (Character.isDigit(ch)) {
                stack.push(ch - '0'); // Convert character to integer and push to the stack
            } else if (ch == ' ') {
                continue; // Skip spaces
            } else {
                int operand2 = stack.pop();
                int operand1 = stack.pop();
                int result;

                switch (ch) {
                    case '+':
                        result = operand1 + operand2;
                        break;
                    case '-':
                        result = operand1 - operand2;
                        break;
                    case '*':
                        result = operand1 * operand2;
                        break;
                    case '/':
                        result = operand1 / operand2;
                        break;
                    default:
                        throw new IllegalArgumentException("Invalid operator: " + ch);
                }

                stack.push(result);
            }
        }

        if (stack.size() != 1) {
            throw new IllegalArgumentException("Invalid postfix expression");
        }

        return stack.pop();
    }

    public static void main(String[] args) {
        String postfixExpression = "2 3 1 * + 9 -";
        int result = evaluatePostfix(postfixExpression);
        System.out.println("Result: " + result);
    }
}

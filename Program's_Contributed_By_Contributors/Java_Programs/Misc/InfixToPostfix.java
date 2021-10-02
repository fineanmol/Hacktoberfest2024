import java.util.LinkedList;

class Stacks {

    private LinkedList<Character> stack = new LinkedList<>();

    public boolean isEmpty() {
        return stack.isEmpty();
    }

    public void push(char value) {
        stack.addFirst(value);
    }

    public Object pop() {
        if (!isEmpty()) {
            return stack.removeFirst();
        } else {
            return null;
        }
    }

    public char peek() {
        if (!isEmpty()) {
            return stack.getFirst();
        } else {
            return ' ';
        }
    }

    public void print() {
        while (!isEmpty()) {
            System.out.print(stack.pop() + ", ");
        }
    }

    @Override
    public String toString() {
        return stack.toString();
    }

    public Object[] toArray() {
        return stack.toArray();
    }

}

public class InfixToPostfix {

    static int Prec(char ch) {
        switch (ch) {
            case '+':
            case '-':
                return 1;

            case '*':
            case '/':
                return 2;

            case '^':
                return 3;
        }
        return -1;
    }

    static String toPostfix(String userInput) {
        Stacks stack = new Stacks();

        String postString = "";
        for (int index = 0; index < userInput.length(); index++) {
            char letter = userInput.charAt(index);
            if (Character.isLetterOrDigit(letter)) {
                postString += letter;
            } else if (letter == '(') {
                stack.push(letter);
            } else if (letter == ')') {
                while (!stack.isEmpty() && stack.peek() != '(') {
                    postString += stack.pop();
                }
                stack.pop();
            } else {
                while (!stack.isEmpty() && Prec(letter) <= Prec(stack.peek())) {
                    postString += stack.pop();
                }
                stack.push(letter);
            }
        }

        while (!stack.isEmpty()) {
            if (stack.peek() == '(') {
                postString += "";
            } else {
                postString += stack.pop();
            }
        }

        return postString;
    }

    public static void main(String[] args) {

        String infixString = "A+B*C+D";
        System.out.println(toPostfix(infixString));
    }
}

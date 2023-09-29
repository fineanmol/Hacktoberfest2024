import java.util.Scanner;

public class SimpleChatBot {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Hello! I'm your simple chatbot. What's your name?");
        String userName = scanner.nextLine();
        System.out.println("Nice to meet you, " + userName + "! How can I assist you today?");

        while (true) {
            String userInput = scanner.nextLine().toLowerCase();

            if (userInput.contains("hello")) {
                System.out.println("Hello, " + userName + "!");
            } else if (userInput.contains("how are you")) {
                System.out.println("I'm just a computer program, but thanks for asking!");
            } else if (userInput.contains("bye")) {
                System.out.println("Goodbye, " + userName + "! Have a great day!");
                break;
            } else {
                System.out.println("I'm not sure how to respond to that. Can you ask something else?");
            }
        }

        scanner.close();
    }
}

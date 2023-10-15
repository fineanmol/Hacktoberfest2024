import java.io.*;
import java.util.*;

class Book {
    String Bname;
    String Bid;
    String Aname;
    String Cost;
}

public class LibraryManagement {
    public static void addRecord(File file, Scanner scanner) throws IOException {
        Book newBook = new Book();
        System.out.print("Enter the Book Name: ");
        newBook.Bname = scanner.nextLine();
        System.out.print("Enter the Book Id: ");
        newBook.Bid = scanner.nextLine();
        System.out.print("Enter the Author Name: ");
        newBook.Aname = scanner.nextLine();
        System.out.print("Enter the cost: ");
        newBook.Cost = scanner.nextLine();
    
        try (PrintWriter writer = new PrintWriter(new FileWriter(file, true))) {
            writer.println(newBook.Bname + "," + newBook.Bid + "," + newBook.Aname + "," + newBook.Cost);
            System.out.println("Added Successfully\n");
        }
    }
    

    public static void displayRecord(File inputFile) throws FileNotFoundException {
        System.out.println("Book List");
        System.out.println("==================================================");

        int count = 0;

        try (Scanner scanner = new Scanner(inputFile)) {
            scanner.useDelimiter(",|\\n");

            while (scanner.hasNext()) {
                count++;
                System.out.println("Book #" + count);

                String Bname = scanner.next();
                String Bid = scanner.next();
                String Aname = scanner.next();
                String Cost = scanner.next();

                System.out.println("Book Name: " + Bname);
                System.out.println("Book Id: " + Bid);
                System.out.println("Author Name: " + Aname);
                System.out.println("Cost: " + Cost);
                System.out.println("---------------------------");
            }
        }

        if (count == 0) {
            System.out.println("Book not found.");
        }
    }


    public static void updateRecord(File inputFile, Scanner scanner) throws IOException {
        System.out.print("Enter the book name to Update: ");
        String searchBookName = scanner.nextLine();

        BufferedReader reader = new BufferedReader(new FileReader(inputFile));
        List<String> lines = new ArrayList<>();

        String line;
        boolean found = false;
        while ((line = reader.readLine()) != null) {
            String[] parts = line.split(",");
            if (parts.length == 4 && parts[0].equals(searchBookName)) {
                found = true;

                System.out.print("Enter updated Book Name: ");
                String updatedBname = scanner.nextLine();
                System.out.print("Enter updated Book Id: ");
                String updatedBid = scanner.nextLine();
                System.out.print("Enter updated Author Name: ");
                String updatedAname = scanner.nextLine();
                System.out.print("Enter updated Cost: ");
                String updatedCost = scanner.nextLine();

                line = updatedBname + "," + updatedBid + "," + updatedAname + "," + updatedCost;
                System.out.println("Book Updated Successfully!!");
            }
            lines.add(line);
        }
        reader.close();

        if (!found) {
            System.out.println("Invalid book!! Please enter correct details.");
        }

        PrintWriter writer = new PrintWriter(new FileWriter(inputFile));
        for (String updatedLine : lines) {
            writer.println(updatedLine);
        }
        writer.close();
    }

    public static void deleteRecord(File inputFile, Scanner scanner) throws IOException {
        System.out.print("Enter the Book name from the list: ");
        String searchBookName = scanner.nextLine();

        BufferedReader reader = new BufferedReader(new FileReader(inputFile));
        List<String> lines = new ArrayList<>();

        String line;
        boolean found = false;
        while ((line = reader.readLine()) != null) {
            String[] parts = line.split(",");
            if (parts.length == 4 && parts[0].equals(searchBookName)) {
                found = true;
            } else {
                lines.add(line);
            }
        }
        reader.close();

        if (!found) {
            System.out.println("Book not found.");
        } else {
            PrintWriter writer = new PrintWriter(new FileWriter(inputFile));
            for (String updatedLine : lines) {
                writer.println(updatedLine);
            }
            writer.close();
            System.out.println("Book deleted Successfully");
        }
    }

    public static void main(String[] args) throws IOException {
        File libraryFile = new File("library.txt");

        if (!libraryFile.exists()) {
            if (!libraryFile.createNewFile()) {
                System.out.println("Error for opening file");
                return;
            }
        }

        PrintWriter fileWriter = new PrintWriter(new FileWriter(libraryFile, true));
        BufferedReader fileReader = new BufferedReader(new FileReader(libraryFile));
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.println("=================================================");
            System.out.println("Book List Menu:");
            System.out.println("1. Add book");
            System.out.println("2. Display Record book");
            System.out.println("3. Update a book");
            System.out.println("4. Delete a book");
            System.out.println("5. Exit\n");

            System.out.print("Enter your Choice (1-5): ");
            int choice = scanner.nextInt();
            scanner.nextLine(); // Consume the newline character

            switch (choice) {
                case 1:
                    System.out.println("Adding a Book...\n");
                    addRecord(libraryFile, scanner);
                    break;
                case 2:
                    System.out.println("Displaying Book Records...\n");
                    displayRecord(libraryFile);
                    break;
                case 3:
                    updateRecord(libraryFile, scanner);
                    break;
                case 4:
                    deleteRecord(libraryFile, scanner);
                    break;
                case 5:
                    System.out.println("Exiting...");
                    scanner.close();
                    fileWriter.close();
                    fileReader.close();
                    return;
                default:
                    System.out.println("Invalid Choice!! Please try again\n");
                    break;
            }
        }
    }
}

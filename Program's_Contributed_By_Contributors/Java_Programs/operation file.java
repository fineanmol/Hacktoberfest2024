/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author firman
 */
import java.io.*;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;
public class file {
    public static void main(String[] args) throws FileNotFoundException, IOException {
        File file = new File("nama");
        file.setWritable(true);
        
        try {
            file.createNewFile();
            } catch (IOException ex) {
            Logger.getLogger(file.class.getName()).log(Level.SEVERE, null, ex);
        }
        try {
            FileInputStream in = new FileInputStream("nama");

        } catch (FileNotFoundException ex) {
            Logger.getLogger(file.class.getName()).log(Level.SEVERE, null, ex);
        }

        FileReader read = new FileReader("nama");
        BufferedReader buf = new BufferedReader(read);

            FileWriter write = new FileWriter("nama");

        String temp = null;
        try {
            temp = buf.readLine();
        } catch (IOException ex) {
            Logger.getLogger(file.class.getName()).log(Level.SEVERE, null, ex);
        }
        if (temp != null ) {
            
          Scanner input = new Scanner(System.in);
          String nama = null;
          nama = input.nextLine();
          write.write(nama);
         
          nama = input.nextLine();
          write.write(nama);
          
          nama = input.nextLine();
          write.write("Bagus Prawira");
          write.close();
        }

    }
}

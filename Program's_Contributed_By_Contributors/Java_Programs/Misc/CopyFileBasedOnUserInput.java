import java.io.*;

public class Copy {
    public static void main(String[] args) throws IOException {
        if(args.length < 2) {
        System.out.println("Parameter hilang di command line");
        System.exit(0);
        }
        System.out.println("Kode sumber file anda ada di: " + args[0]);
        System.out.println("Destinasi: " + args[1]);

        File file1 = new File(args[0]);
        File file2 = new File(args[1]);

        FileInputStream src = new FileInputStream(file1);
        FileOutputStream dst = new FileOutputStream(file2);

        int data = src.read();
        while(data != -1) {
            dst.write((char)data);
            data = src.read();
        }

        System.out.println("File berhasil dicopy!");
        src.close();
        dst.close();
    }
}
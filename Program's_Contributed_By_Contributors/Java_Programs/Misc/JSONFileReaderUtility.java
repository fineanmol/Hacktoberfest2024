import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

public class JSONFileReaderUtility {
    
    public static void main(String[] args) throws Exception {
        String filePath = "../Resources/SampleJSON.json";
        String response = readJSONFile(filePath);
        System.out.println(response);
    }

    public static String readJSONFile(String filePath) throws IOException {
        return new String(Files.readAllBytes(Paths.get(filePath)));
    }
}
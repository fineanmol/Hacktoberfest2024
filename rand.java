import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Random;

public class UniqueProjectCodeGenerator {

    public static String generateUniqueCode() {
        SimpleDateFormat dateFormat = new SimpleDateFormat("yyyyMMddHHmmss");
        String timestamp = dateFormat.format(new Date());

        Random random = new Random();
        int randomNum = random.nextInt(10000);

        return "PROJ-" + timestamp + "-" + String.format("%04d", randomNum);
    }

    public static void main(String[] args) {
        String uniqueCode = generateUniqueCode();
        System.out.println("Unique Project Code: " + uniqueCode);
    }
}

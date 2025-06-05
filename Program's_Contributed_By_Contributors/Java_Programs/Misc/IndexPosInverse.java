import java.io.*;

public class IndexPosInverse {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Long n = Long.parseLong(br.readLine());

        Long ans = (long) 0;
        int i = 1;
        while (n != 0) {
            ans += i * (int) Math.pow(10, (n % 10) - 1);
            n /= 10;
            i++;
        }

        System.out.println(ans);
    }
}

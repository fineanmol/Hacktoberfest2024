//password generator
import java.util.Random;

import javax.swing.JOptionPane;

public class Main {
	public static void main(String Args[]) {
		int c = Integer.parseInt(JOptionPane.showInputDialog("A password of how many characters?"));
		String password = "";
		Random r = new Random();
		for (int i = 0; i < c; i++) {
			password += (char) (97 + r.nextInt(25));
		}

		JOptionPane.showMessageDialog(null, password);
	}
}

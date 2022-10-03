import javax.swing.JOptionPane;
 class solution{
    public static void main(String args[]){
        String s = JOptionPane.showInputDialog(null, "Enter your number");
        int n = Integer.parseInt(s);
        for(int i=1; i<=n; i++) {
            if (n % i == 0){
                System.out.println(i);
            }
        }
    }
 }
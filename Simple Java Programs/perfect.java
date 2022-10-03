 import javax.swing.JOptionPane;
 class perfect {
    public static void main(String[] args) {
        int i=1, n;
        String s1 = JOptionPane.showInputDialog(null, "Enter your number");
        n = Integer.parseInt(s1);
        while(i<=n){
            if(n % i == 0) {
                System.out.println(i);
                i++;
            }
            }
        }
    }

/*
 import javax.swing.JoptionPane;
 class solution{
    public static void main(String args[]){
        String s = JoptionPane.showInputDialog(null, "Enter your number");
        n = Integer.parseInt(s);
        for(i=1; i<=n; i++) {
            System.out.println(i);
        }
    }
 }
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class ValidatePassword {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String senha;
        while ((senha = br.readLine()) !=null) {
            boolean valida = true;
            if (temMaiuscula(senha) && (temMinuscula(senha)) && (!semEspacos(senha)) && (semSimbol(senha)) && (semAcentos(senha)) && (temTamanhoadq(senha)) && (temNumero(senha))) {
                System.out.println("Senha valida.");
            } else {
                System.out.println("Senha invalida.");
            }
        }
//				for (int i = 0; i < 200; i++) {
//					System.out.println(i + "-" + (char) i);
//				}
    }

    private static boolean temMaiuscula(String senha) {
        for (int i = 0; i < senha.length(); i++) {
            if (senha.charAt(i) >= 65 && senha.charAt(i) <= 90) {
                return true;
            }
        }
        return false;
    }

    private static boolean temNumero(String senha) {
        for (int i = 0; i < senha.length(); i++) {
            if (senha.charAt(i) >= 48 && senha.charAt(i) <= 57) {
                return true;
            }

        }
        return false;
    }

    private static boolean temMinuscula(String senha) {
        for (int i = 0; i < senha.length(); i++) {
            if (senha.charAt(i) >= 97 && senha.charAt(i) <= 122) {
                return true;
            }
        }
        return false;
    }

    private static boolean temTamanhoadq(String senha) {
        int tamanho = senha.length();
        if (tamanho >= 6 && tamanho <= 32) {
            return true;
        }
        return false;

    }
    private static boolean semEspacos(String senha) {
        for (int i = 0; i < senha.length(); i++) {
            char letra = senha.charAt(i);
            if(letra==' '){
                return true;
            }
        }
        return false;
    }
    private static boolean semSimbol(String senha){
        for (int i = 0; i < senha.length(); i++) {
            if(!(senha.charAt(i)>=48 && senha.charAt(i)<=57) &&
                    !(senha.charAt(i)>=65 && senha.charAt(i)<=90) &&
                    !(senha.charAt(i)>=97 && senha.charAt(i)<=122)){
                return false;
            }
        }
        return true;
    }
    private static boolean semAcentos(String senha){
//				for (int i = 0; i < senha.length(); i++) {
//					if(senha.charAt(i)>=91 && senha.charAt(i)<=96){
//						return false;
//					}
//				}
        return true;
    }
}

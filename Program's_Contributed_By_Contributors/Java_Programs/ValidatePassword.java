public class ValidatePassword {
    public static void main(String[] args) {
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
    }
}

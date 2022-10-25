package heranca.uperDownCase;

/**
 * Classe principal do exercício  4 do modulo de POO
 * */
public class Main {

    public static void main(String[] args){

        Funcionarios funcionarios = new Funcionarios();

        Funcionarios gerente = new Gerente();
        Funcionarios faxineiro = new Faxineiro();
        Funcionarios vendedor = new Vendedor();

        // O Downcast abaixo foi feito apenas para fins do exercício
        //Vendedor vendedor_ = (Vendedor) new Funcionarios();
    }
}

package heranca.exercicio1;

public class veiculo {
    String placa;
    String combustivel;
    String fabricante;
    int cavalos;
    int rodas;
    int marchas;

    public void andar(){
        System.out.println("O carro andou para frente");
    }

    public void freiar(){
        System.out.print("O carro freiou");
    }

    public void alarme(){
        System.out.print("O carro esta alarmando");
    }
}

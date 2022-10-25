package questao04;

//Crie uma classe VIP, que herda Ingresso e possui um valor adicional. Crie um metodo que retorne o valor do igresso VIP (com o adicional)

public class VIP extends Ingresso {
	int valorAdicional = 5;
	
	public void imprimeIngressoVip () {
		System.out.println("Valor do ingresso VIP: " + (valorReal + valorAdicional) + (" reais."));
				
	}
}

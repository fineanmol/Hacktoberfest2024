package questao04;

//Crie uma classe CamaroteSuperior, que é mais cara (possui um valor adicional). Esta ultima possui um metodo para retornar o valor do ingresso.
//Herda VIP

public class CamaroteSuperior extends VIP{
	int valorAdicionalCamarote = 10;
	
	public void valorIngressoCamaroteSuperior() {
		System.out.println("O valor do ingresso do camarote superior é: " + (valorReal + valorAdicionalCamarote) + (" reais."));
	}

}

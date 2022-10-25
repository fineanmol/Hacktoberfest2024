package questao04;

//Crie uma classe CamaroteInferior (quepossui a localização do ingresso e metodos para acessar e imprimir esta localização)
//Herda VIP

public class CamaroteInferior extends VIP{
	String localizacaoIngresso = "AB4";
	
	public void imprimirLocalizacao() {
		System.out.println("Seu ingresso está na localização: " + localizacaoIngresso);
	}
	
}

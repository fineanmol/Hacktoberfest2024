package questao04;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		VIP vip1 = new VIP();
		vip1.imprimeIngressoVip();
		
		Normal normal1 = new Normal();
		normal1.ingressoNormal();
		
		CamaroteInferior camaroteI1 = new CamaroteInferior();
		camaroteI1.imprimirLocalizacao();
		
		CamaroteSuperior camaroteS1 = new CamaroteSuperior();
		camaroteS1.valorIngressoCamaroteSuperior();

	}

}

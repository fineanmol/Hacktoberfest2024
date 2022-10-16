import java.util.Date;

public class Venda {
	
	private Date data = new Date();
	private Produto[] produtos = new Produto[1];

	public Venda(){

	}
	
	public void adicioneProduto(Produto p) {
		int i;
		Produto[] aux =  new Produto[produtos.length+1];
	
		if (produtos[0] == null) {
			produtos[0] = p;			
		} else {
			for (i = 0; i < produtos.length; i++) {
				aux[i] = produtos[i];
			}
			aux[aux.length-1] = p;		
			produtos = aux;
		}
		
	}
	
	public double getTotal() { 
		double total = 0.0;
		for (int i=0; i < produtos.length ;i++) {
			total += produtos[i].getPreco();
		}
		return total;
	}

	@Override
	public String toString(){
		String notaFiscal = this.data + "\n";
		for(int i = 0; i < produtos.length; i++){
			notaFiscal += this.produtos[i].toString() + "\n";
		}
		notaFiscal += "\n" + "Total: R$ " + getTotal() + "\n";
		return notaFiscal;
	}

}
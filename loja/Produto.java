
public class Produto {
	
	private double preco;
	private String descricao;
	
	public Produto(double preco, String descricao) {
		this.preco = preco;
		this.descricao = descricao;
	}
	
	public double getPreco() {
		return preco;
	}
	
	public void setPreco(double preco) {
		this.preco = preco;
	}
	
	@Override
	public String toString() {
		return "Descricao: " + this.descricao + " - Preço: R$ "+ this.preco ;
		
	}
	
	

}
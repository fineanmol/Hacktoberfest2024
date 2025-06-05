public class VendaVista extends Venda {
	
	private int desconto;

	public VendaVista(int desconto){
		this.desconto = desconto;
	}

	@Override
	public double getTotal() {
		return super.getTotal() - this.desconto;
	}

	@Override
	public String toString(){
		return String.format("\n%s\n%s%d%s\n",super.toString(), "Desconto de : R$ ", this.desconto,".00");
	}
}
public class VendaPrazo extends Venda {
	private int juros;

	public VendaPrazo(int juros){
		this.juros = juros;
	}

	@Override
	public double getTotal() { 
		return super.getTotal()*(1+juros/100.0);
	}

	@Override
	public String toString(){
		return String.format("\n%s\n%s%d%s\n",super.toString(), "Juros de : ", this.juros,"%");
	}

}
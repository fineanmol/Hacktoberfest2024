public class Caixa {
	
	public static void main(String args[]) {
		Venda venda = new Venda();
		VendaPrazo prazo = new VendaPrazo(2);
		VendaVista vista = new VendaVista(10);
		
		Produto produto1 = new Produto(8.0, "Arroz");
		venda.adicioneProduto(produto1);
		prazo.adicioneProduto(produto1);
		vista.adicioneProduto(produto1);
		Produto produto2 = new Produto(15.0, "Melancia");
		venda.adicioneProduto(produto2);
		prazo.adicioneProduto(produto2);
		vista.adicioneProduto(produto2);
		Produto produto3 = new Produto(6.0, "Macarrão");
		venda.adicioneProduto(produto3);
		prazo.adicioneProduto(produto3);
		vista.adicioneProduto(produto3);
		Produto produto4 = new Produto(3.0, "Iogurte");
		venda.adicioneProduto(produto4);
		prazo.adicioneProduto(produto4);
		vista.adicioneProduto(produto4);
		Produto produto5 = new Produto(7.0, "Queijo");
		venda.adicioneProduto(produto5);
		prazo.adicioneProduto(produto5);
		vista.adicioneProduto(produto5);
		Produto produto6 = new Produto(18.0, "Bacon");
		venda.adicioneProduto(produto6);
		prazo.adicioneProduto(produto6);
		vista.adicioneProduto(produto6);
		Produto produto7 = new Produto(4.0, "Biscoito");
		venda.adicioneProduto(produto7);
		prazo.adicioneProduto(produto7);
		vista.adicioneProduto(produto7);
		Produto produto8 = new Produto(25.0, "Açaí");
		venda.adicioneProduto(produto8);
		prazo.adicioneProduto(produto8);
		vista.adicioneProduto(produto8);	
		Produto produto9 = new Produto(35.0, "Camarão");
		venda.adicioneProduto(produto9);
		prazo.adicioneProduto(produto9);
		vista.adicioneProduto(produto9);
		Produto produto10 = new Produto(10.0, "Feijão");
		venda.adicioneProduto(produto10);
		prazo.adicioneProduto(produto10);
		vista.adicioneProduto(produto10);


		System.out.println(venda.toString());
		System.out.println(prazo.toString());
		System.out.println(vista.toString());


		
	}

}
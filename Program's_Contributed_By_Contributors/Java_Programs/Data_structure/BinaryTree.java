
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class BinaryTree<T> {

    private BinaryNode<T> root;

    public BinaryTree() {
        this.root = new BinaryNode<>();
    }

    public BinaryTree(T content) {
        this.root = new BinaryNode<>(content);
    }

    public BinaryNode<T> getRoot() {
        return root;
    }

    public void setRoot(BinaryNode<T> root) {
        this.root = root;
    }

    public void setLeft(BinaryTree<T> tree) {
        this.root.setLeft(tree);
    }

    public void setRight(BinaryTree<T> tree) {
        this.root.setRight(tree);
    }

    public BinaryTree<T> getLeft() {
        return this.root.getLeft();
    }

    public BinaryTree<T> getRight() {
        return this.root.getRight();
    }

    public boolean isEmpty() {
        return this.root == null;
    }
    public void Imprimir(){
        if(this.getLeft()!=null){
            System.out.println(this.getLeft().getRoot().getContent());
            this.getLeft().Imprimir();
        }
        if(this.getRight()!=null){
            System.out.println(this.getRight().getRoot().getContent());
            this.getRight().Imprimir();
        }
    }
    
    
    
    

    public boolean isLeaf() {
        return this.root.getLeft() == null && this.root.getRight() == null;
    }
    public void createCompleteTree(ArrayList<Integer> lista){
        if(this.root.getContent()==null && !lista.isEmpty()){
            this.setRoot(new BinaryNode(lista.get(0)));
            System.out.println("Sucede ");
        }
        if(lista.size()>1){
            ArrayList<Integer> l=RecortarListaImpar(0,lista);
           BinaryTree tree= new BinaryTree(l.get(0));
            this.root.setLeft(tree); 
            System.out.println("Pasa para arbol izquierda: "+tree.getRoot().getContent());
            System.out.println("Lista: "+lista+"\n");
            tree.createCompleteTree(RecortarListaImpar(1,l));
        }
        if(lista.size()>2){
            ArrayList<Integer> l=RecortarListaPar(0,lista);
            BinaryTree tree= new BinaryTree(l.get(0));
            this.root.setRight(tree);
            System.out.println("Pasa para arbol derecha: "+tree.getRoot().getContent());
            System.out.println("Lista: "+lista+"\n");
            tree.createCompleteTree(RecortarListaPar(1,l));
        } 
//        
//        if(this.root.getLeft()!=null ){
//            BinaryTree tree= new BinaryTree(lista.get(1));
//            this.root.setLeft(tree);
//            System.out.println("Pasa para arbol izquierda: "+tree.getRoot().getContent());
//            System.out.println("Lista: "+lista+"\n");
//            tree.createCompleteTree(RecortarLista(2,lista));
//        }
//        if(this.root.getRight()!=null ){
//            BinaryTree tree= new BinaryTree(lista.get(2));
//            this.root.setRight(tree);
//            System.out.println("Pasa para arbol derecha: "+tree.getRoot().getContent());
//            System.out.println("Lista: "+lista+"\n");
//            tree.createCompleteTree(RecortarLista(2,lista));
//        }
    }
    private ArrayList<Integer> RecortarLista(int inicio, ArrayList<Integer> lista){
        ArrayList<Integer> l= new ArrayList();
        for(int i=inicio;i<lista.size();i++){
            l.add(lista.get(i));
        }
        return l;
    }
    private ArrayList<Integer> RecortarListaPar(int inicio, ArrayList<Integer> lista){
        ArrayList<Integer> l= new ArrayList();
        for(int i=inicio;i<lista.size();i++){
            if(i%2==0){
            l.add(lista.get(i));}
        }
        return l;
    }
    private ArrayList<Integer> RecortarListaImpar(int inicio, ArrayList<Integer> lista){
        ArrayList<Integer> l= new ArrayList();
        for(int i=inicio;i<lista.size();i++){
            if(i%2!=0){
            l.add(lista.get(i));}
        }
        return l;
    }
//    public BinaryTree<Integer> createCompleteTree(ArrayList<Integer> lista){
//        BinaryTree raiz= new BinaryTree(lista.get(0));
//        for(int i=1;i<lista.size();i++){
//            BinaryTree padre=null;
//            //2 es hijo siempre de 0 no de 1
//            if(i==2){
//                padre=raiz.BuscarNodo(lista.get(0));
//                padre.root.setRight(new BinaryTree(lista.get(i)));
//            }
//            //si el indice es par se busca al padre
//            else if(i%2==0){
//                padre=raiz.BuscarNodo(lista.get(i/2));
//                padre.root.setRight(new BinaryTree(lista.get(i)));
//            }
//            //si el indices es impar se busca al padre
//            else{
//                padre=raiz.BuscarNodo(lista.get((i-1)/2));
//                padre.root.setLeft(new BinaryTree(lista.get(i)));
//            }
//            
//        }
//        return raiz;
//    }
    public BinaryTree<Integer> findIntersection(BinaryTree<Integer> BT1,BinaryTree<Integer>BT2){
        BinaryTree<Integer> arbol= new BinaryTree();
        //Verificando que sus izquierdos no sean nulos en la misma posicion
        if(BT1.getRoot().getLeft()!=null && BT2.getRoot().getLeft()!=null){
            arbol.root.setContent(BT1.getRoot().getContent()+BT2.getRoot().getContent());
            arbol.setLeft(findIntersection(BT1.getLeft(),BT2.getLeft()));
        }
        //Verificando que sus derechos no sean nulos en la misma posicion
        if(BT1.getRoot().getRight()!=null && BT2.getRoot().getRight()!=null){
            arbol.root.setContent(BT1.getRoot().getContent()+BT2.getRoot().getContent());
            arbol.setRight(findIntersection(BT1.getRight(),BT2.getRight()));
        }
        
        if(BT1.getRoot()!=null && BT2.getRoot()!=null){
        arbol.getRoot().setContent(BT1.getRoot().getContent()+BT2.getRoot().getContent());}
        else{ return null;}
        
        return arbol;
    }

    public int size() {
        int size = 0;
        if (this.isEmpty()) {
            return 0;
        }
        if (!this.isEmpty()) {
            size += 1;
        }
        if (this.root.getLeft() != null) {
            size += this.root.getLeft().size();
            //System.out.println(size);
        }
        if (this.root.getRight() != null) {
            size += this.root.getRight().size();
        }
        return size;
    }
    public boolean hasSymmetricStructure(){
        boolean bo=true;
        //si los 2 son nulos a la vez
        if(this.getRight()==null && this.getLeft()==null){
            return true;}
        //si cualquiera de los 2 son nulos sin incluir cuando los 2 a la vez son nulos
        else if(this.getRight()==null || this.getLeft()==null){
            return false;}
        else{
            BinaryTree<T> izquierda=this.getLeft();
            BinaryTree<T> derecha=this.getRight();
            //creamos una cola para los nodos de izquierda y derechas del nodo raiz solamente
            Queue<BinaryTree<T>> colaIZQ= new LinkedList();
            Queue<BinaryTree<T>> colaDER= new LinkedList();
            colaIZQ.add(izquierda);
            colaDER.add(derecha);
            while(!colaIZQ.isEmpty() && !colaDER.isEmpty()){
                BinaryTree<T> izq=colaIZQ.remove();
                BinaryTree<T> der=colaDER.remove();
                //comprobamos que los hijos izquierdos no sean nulos a la vez
                if(izq.getLeft()!=null && der.getLeft()!=null){
                    bo=bo && true;
                    colaIZQ.add(izq.getLeft());
                    colaDER.add(der.getLeft());}
                //comprobamos que los hijos izquierdos sean nulos a la vez
                else if(izq.getLeft()==null && der.getLeft()==null){
                    bo=bo && true;}
                //este es el caso cuando uno es nulo y el otro no es decir cuando ya no seria simetrico
                else{
                    return false;}
                //comprobamos que los hijos derechos no sean nulos a la vez
                if(izq.getRight()!=null && der.getRight()!=null){
                    bo=bo && true;
                    colaIZQ.add(izq.getRight());
                    colaDER.add(der.getRight());}
                //comprobamos que los hijos derechos no sean nulos a la vez
                else if(izq.getRight()!=null && der.getRight()!=null){
                    bo=bo && true;}
                //este es el caso cuando uno es nulo y el otro no es decir cuando ya no seria simetrico
                else{
                    return false;}}}
        return bo;
    }
    
     public boolean cumpleHojas (){
         if(this.root==null){
             return true;
         }
         boolean bo=true;
         //ejecutamos el metodo recursivamente
         if(this.root.getLeft()!=null){
             //igualamos a bo es igual a bo y el resultado de lo anterior si al menos
             //en una llega a ser falso todo bo se vuelve falso
             bo= bo && this.getLeft().cumpleHojas();
         }
         if(this.root.getRight()!=null){
             bo= bo &&this.getRight().cumpleHojas();
         }
         //verificamos si para cada nodo se cumple que su valor es igual a su numero de hojas
         if(this.root!=null){
             //countLeavesRecursive() retorna el numero de hojas que contiene un arbol 
             bo= bo && (this.root.getContent()==this.countLeavesRecursive());
             
         }
         return bo;
     }

    public int countLeavesRecursive() {
        if (this.isEmpty()) {
            return 0;
        } else if (this.isLeaf()) {
            return 1;
        } else {
            int leavesLeft = 0;
            int leavesRight = 0;
            if (this.root.getLeft() != null) {
                leavesLeft = this.root.getLeft().countLeavesRecursive();
            }
            if (this.root.getRight() != null) {
                leavesRight = this.root.getRight().countLeavesRecursive();
            }
            return leavesLeft + leavesRight;
        }
    }

    public int countLeavesIterative() {
        Stack<BinaryTree<T>> stack = new Stack();
        int count = 0;
        if (this.isEmpty()) {
            return count;
        } else {
            stack.push(this);
            while (!stack.empty()) {
                BinaryTree<T> subtree = stack.pop();
                if (subtree.root.getLeft() != null) {
                    stack.push(subtree.root.getLeft());
                }
                if (subtree.root.getRight() != null) {
                    stack.push(subtree.root.getRight());
                }
                if (subtree.isLeaf()) {
                    count++;
                }
            }
        }
        return count;
    }

    public BinaryNode<T> recursiveSearch(T content) {
        if (this.isEmpty()) {
            return null;
        } else {
            if (this.root.getContent().equals(content)) {
                return this.root;
            } else {
                BinaryNode<T> tmp = null;
                if (this.root.getLeft() != null) {
                    tmp = this.root.getLeft().recursiveSearch(content);
                }
                if (tmp == null) {
                    if (this.root.getRight() != null) {
                        return this.root.getRight().recursiveSearch(content);
                    }
                }
                return tmp;
            }
        }
    }

    public BinaryNode<T> recursiveSearchIterative(T content) {
        if (this.isEmpty()) {
            return null;
        } else if (this.root.getContent().equals(content)) {
            return this.root;
        } else {
            Stack<BinaryTree<T>> pila = new Stack();
            pila.push(this);
            while (!pila.empty()) {
                BinaryTree<T> subtree = pila.pop();
                if (subtree.root.getLeft() != null) {
                    pila.push(subtree.root.getLeft());
                }
                if (subtree.root.getRight() != null) {
                    pila.push(subtree.root.getRight());
                }
                if (subtree.root.getContent().equals(content)) {
                    return subtree.root;
                }
            }

        }
        return null;
    }

    public void printInorden() {
        if (!this.isEmpty()) {

            Stack<BinaryTree> pila = new Stack();
            pila.push(this);
            int cont = 0;
            while (!pila.isEmpty()) {
                BinaryTree<T> subtree = pila.pop();
                if (!subtree.equals(this)) {
                    System.out.println(subtree.root.getContent());
                }
                if (subtree.root.getRight() != null) {
                    pila.push(subtree.root.getRight());
                }
                if (subtree.root.getLeft() != null) {
                    pila.push(subtree.root.getLeft());
                }
                if (subtree.root.getRight() == null && cont == 0) {
                    System.out.println(this.root.getContent());
                    cont++;
                }

            }

        }
    }

    public void printPreorden() {
        if (!this.isEmpty()) {

            Stack<BinaryTree> pila = new Stack();
            pila.push(this);
            while (!pila.isEmpty()) {
                BinaryTree<T> subtree = pila.pop();
                System.out.println(subtree.root.getContent());
                if (subtree.root.getRight() != null) {
                    pila.push(subtree.root.getRight());
                }
                if (subtree.root.getLeft() != null) {
                    pila.push(subtree.root.getLeft());
                }

            }
        }
    }

    public void printPostorden() {
        if (!this.isEmpty()) {

            Stack<BinaryTree> pila = new Stack();
            pila.push(this);
            while (!pila.isEmpty()) {
                BinaryTree<T> subtree = pila.pop();
                if (!subtree.equals(this)) {
                    System.out.println(subtree.root.getContent());
                }
                if (subtree.root.getRight() != null) {
                    pila.push(subtree.root.getRight());
                }
                if (subtree.root.getLeft() != null) {
                    pila.push(subtree.root.getLeft());
                }

            }
            System.out.println(this.root.getContent());
        }
    }

//    public int getMin() {
//        
//        int minimo = (int) this.root.getContent();
//        if (this.root != null) {
//            int num = 0;
//
//            if (this.root.getRight() != null) {
//                num = this.root.getRight().getMin();
//                if (num <= minimo) {
//                    minimo = num;
//                }
//            }
//            if (this.root.getLeft() != null) {
//                num = this.root.getLeft().getMin();
//                if (num <= minimo) {
//                    minimo = num;
//                }
//            }
//
//        }
//        return minimo;
//    }

    public int countLevels() {
        if (this.isEmpty()) {
            return 0;
        }
        int levels = 1;
        if (this.isLeaf()) {
            return 1;
        }
        if (this.root != null) {
            if (this.root.getRight() == null) {
                levels = 1 + this.root.getLeft().countLevels();
            } else if (this.root.getLeft() == null) {
                levels = 1 + this.root.getRight().countLevels();
            } else {
                levels = 1 + Math.max(this.root.getRight().countLevels(), this.root.getLeft().countLevels());
            }
        }
        return levels;
    }

    public boolean isLefty() {
        if (this.isEmpty()) {
            return true;
        } else if (this.isLeaf()) {
            return true;
        } else {
            Stack<BinaryTree> pila = new Stack();
            pila.add(this);
            int lefty = 0;
            int rigth = 0;
            while (!pila.isEmpty()) {
                BinaryTree temp = pila.pop();
                if (temp.root.getLeft() != null) {
                    lefty++;
                    pila.add(temp.root.getLeft());
                }
                if (temp.root.getRight() != null) {
                    rigth++;
                    pila.add(temp.root.getRight());
                }
            }
            if (lefty > rigth) {
                return true;
            }
        }
        return false;
    }

    public boolean isIdentical(BinaryTree arbolito) {
        boolean identico = true;
        if (this.isEmpty() && arbolito.isEmpty()) {
            return true;
        }
        if (!this.isEmpty() && !arbolito.isEmpty()) {
            identico = this.root.getContent() == arbolito.root.getContent();
        } else {
            identico = false;
        }
        //Recursividad izquierda
        if (this.root.getLeft() != null && arbolito.root.getLeft() != null) {
            identico = identico && this.root.getLeft().isIdentical(arbolito.root.getLeft());

        } else if (this.root.getLeft() == null && arbolito.root.getLeft() != null) {
            identico = false;
        } else if (this.root.getLeft() != null && arbolito.root.getLeft() == null) {
            identico = false;
        }
        //Recursividad derecha
        if (this.root.getRight() != null && arbolito.root.getRight() != null) {
            identico = identico && this.root.getRight().isIdentical(arbolito.root.getRight());

        } else if (this.root.getRight() == null && arbolito.root.getRight() != null) {
            identico = false;
        } else if (this.root.getRight() != null && arbolito.root.getRight() == null) {
            identico = false;
        }
        return identico;

    }

    public void largestValueOfEachLevel() {
        Queue<BinaryTree> cola = new LinkedList();
        cola.add(this);
        System.out.println(this.root.getContent());
        int nivel=1;
        int numeroElemento=1;
        while (!cola.isEmpty()) {
            BinaryTree temp = cola.remove();
           //Esto debe ir antes de los if que agregan sus izquierdos y derechos ya que este seria el elemento final de cada nivel
            if(numeroElemento==Math.pow(2, nivel)-1){
                int maximo=(int)temp.root.getContent();
                Queue<BinaryTree> numeros=new LinkedList(cola);
                while(!numeros.isEmpty()){
                    BinaryTree p= numeros.remove();
                    maximo=Math.max(maximo,(int) p.root.getContent());
                    
                }
                System.out.println("Maximo: "+maximo);
               
                nivel++;
            }
            int num1 = 0;
            int num2 = 0;
            if (temp.root.getRight() != null) {
                num1 = (int) temp.root.getRight().getRoot().getContent();
                cola.add(temp.root.getRight());
                numeroElemento++;
            }
            else{
                numeroElemento++;
            }
            if (temp.root.getLeft() != null) {
                num2 = (int) temp.root.getLeft().getRoot().getContent();
                cola.add(temp.root.getLeft());
                numeroElemento++;

            }
            else{
                numeroElemento++;
            }
//            if (temp.root.getRight() != null || temp.root.getLeft() != null) {
//                System.out.println(Math.max(num2, num1));
//            }
            
            
        }
    }

    public int countNodesWithOnlyChild() {
        int num = 0;
        if (this.isEmpty()) {
            return 0;
        } else {
            Stack<BinaryTree> pila = new Stack();
            pila.add(this);
            while (!pila.isEmpty()) {
                BinaryTree temp = pila.pop();
                if (temp.root.getLeft() == null && temp.root.getRight() != null) {
                    num += 1;
                } else if (temp.root.getRight() == null && temp.root.getLeft() != null) {
                    num += 1;
                }
                if (temp.root.getLeft() != null) {
                    pila.add(temp.root.getLeft());
                }
                if (temp.root.getRight() != null) {
                    pila.add(temp.getRight());
                }
            }
        }
        return num;
    }

    public boolean isHeightBalanced() {
        if (this.isEmpty()) {
            return true;
        }
        return Math.abs(this.root.getLeft().size() - this.root.getRight().size()) < 2;
    }

}

package packageDA;

public class BSTreeDemo {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BSTree t =new BSTree();
		t.addNode(10);
		t.addNode(5);
		t.addNode(3);
		t.addNode(20);
		t.addNode(6);
		t.addNode(15);
		t.addNode(2);
		t.addNode(25);
		t.inOrderTraversal(t.root);
		System.out.println();
		t.postOrderTraversal(t.root);
		System.out.println();
		t.preOrderTraversal(t.root);
		System.out.println();
		System.out.println("finding 6 = "+t.findNode(6));
	    System.out.println("finding 9 = "+t.findNode(9));
	}

}


class BSTNode {
	 int data;
	 BSTNode leftChild;
	 BSTNode rightChild;
	 
	 public BSTNode(int data){
	 this.data=data;
	 }
	 @Override
	 public String toString(){
	 return "data -> "+data;
	 }
	}

class BSTree {
	 BSTNode root;
	 //see inked screenshot 
	 public void addNode(int data) {
		 BSTNode newNode = new BSTNode(data);
		 if(root==null) {
			 root=newNode;
		 }else {
			 BSTNode currentNode = root;
			 while(true) {
				 BSTNode parentNode = currentNode;
				 if(newNode.data < currentNode.data) {
					 currentNode = currentNode.leftChild;
					 if(currentNode==null) {
						parentNode.leftChild = newNode;
						return;
					 }
				 }else {
					 currentNode = currentNode.rightChild;
					 if(currentNode==null) {
							parentNode.rightChild = newNode;
							return;
						 }
				 }
			 }
		 }
	 }
	 
	 
	 public BSTNode findNode(int data){
	        BSTNode currentNode = root;
	        while(currentNode != null) {
	            if(data == currentNode.data){
	                return currentNode;
	            } else{
	                if(data<currentNode.data){
	                    currentNode =currentNode.leftChild;
	                } else {
	                    currentNode = currentNode.rightChild;
	                }
	            }
	        }
	        return null;
	    }
	 
	 public void preOrderTraversal(BSTNode currentNode){
	        if(currentNode == null){
	            return;
	        }
	        System.out.println(currentNode);
	        preOrderTraversal(currentNode.leftChild);
	        preOrderTraversal(currentNode.rightChild);
	    }
	    
	    public void postOrderTraversal(BSTNode currentNode){
	        if(currentNode == null){
	            return;
	        }
	        postOrderTraversal(currentNode.leftChild);
	        postOrderTraversal(currentNode.rightChild);
	        System.out.println(currentNode);
	    }
	    
	    public void inOrderTraversal(BSTNode currentNode){
	        if(currentNode == null){
	            return;
	        }
	        inOrderTraversal(currentNode.leftChild);
	        System.out.println(currentNode);
	        inOrderTraversal(currentNode.rightChild);
	    }
	 
	}





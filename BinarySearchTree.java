/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tree;

/**
 *
 * @author Zohaib Hassan Soomro
 */
public class BinarySearchTree {
int key;
BinarySearchTree left, right;

BinarySearchTree(int key) {
    this.key = key;
}

BinarySearchTree(int key, BinarySearchTree left, BinarySearchTree right) {
    this.key = key;
    this.left = left;
    this.right = right;
}

/*//in-order traversal of  Binary Tree
public void inOrder() {
    if(this==null)
    	System.out.println("");
    if(this.left==null)
    	System.out.print(".");
    else{
    	System.out.print(left.key+"=>");
    	left.inOrder();
    }
    System.out.print(key);
    if(this.right==null)
    	System.out.println(".");
    else{
    	System.out.println("<="+right.key);
    	right.inOrder();
    }
}*/

//in-order traversal of  Binary Tree
public String toString() {
    if(this==null)
    	return " ";
    String buf="";
 	if(left!=null)
 		buf+=left+" ";
 	buf+=key;
 	if (right!=null)
 		buf+=" "+right;
 	return buf;
}

public String preOrder() {
    if(this==null)
    	return " ";
    String buf=key+"";
 	if(left!=null)
 		buf+=" "+left.preOrder();
 	if (right!=null)
 		buf+=" "+right.preOrder();
 	return buf;
}
public String postOrder() {
    if(this==null)
    	return " ";
    String buf="";
 	if(left!=null)
 		buf+=left.postOrder()+" ";
 	if (right!=null)
 		buf+=right.postOrder()+" ";
 	buf+=key;
 	return buf;
}
public void traverse(){
	System.out.println("Inorder  : "+toString());
	System.out.println("Preorder : "+preOrder());
	System.out.println("Postorder: "+postOrder());
}

public BinarySearchTree insert(int key){
	return insert(this,key);
}
private BinarySearchTree insert(BinarySearchTree root, int key){
	if(root==null)
		return new BinarySearchTree(key);
	if(key<root.key){
		root.left=insert(root.left,key);
	}
	if(key>root.key){
		root.right=insert(root.right,key);
	}
	else if(key==root.key){
		System.out.println("Duplicate values not allowed here!");
		return root;
	}
	return root;
}

public boolean search(int key){
	return search(this,key);
}
private boolean search(BinarySearchTree root, int key){
	if(root==null)
		return false;
	if(key<root.key){
		return search(root.left,key);
	}
	if(key>root.key){
		return search(root.right,key);
	}
	else if(key==root.key){
		return true;
	}
	return false;
}

public boolean delete(int key){
	return delete(this,key);
}

public boolean delete(BinarySearchTree root,int key){
	if(root==null)
		return false;
	if(key<root.key)
		return left.delete(left,key);
	if(key>root.key)
		return right.delete(right,key);
	if(root.left==null && root.right==null){
		root=null;
		return true;
	}
	if (root.right==null) {
		root=root.left;
		root.right=root.left.right;
		root.left=root.left.left;
		return true;
	}

	if (root.left==null) {
		root=root.right;
		root.left=root.right.left;
		root.right=root.right.right;
		return true;
	}

	if(root.right.left==null){
		root=root.right;
		root.right=root.right.right;
		return true;
	}

	root=deleteMinimum(root.right);
	return true;
}

private BinarySearchTree deleteMinimum(BinarySearchTree root){
	if(root.left.left==null){
		BinarySearchTree temp=root.left;
		root.left=root.left.right;
		return temp;
	}
	return root.deleteMinimum(root.left);
}
/*private BinarySearchTree delete(BinarySearchTree root, int key){
	if(root==null)
		return root;
	if(!search(root,key)){
		System.out.println("Value not found!");
		return root;
	}
	if(key<root.key)
		return delete(root.left,key);
	if(key>root.key)
		return delete(root.right,key);
	if(key==root.key && root.left==null && root.right==null){
		BinarySearchTree p=getParent(root);
		if(p.left==root)
			return p.left=root.left; //return root=root.right
		else if(p.right==root)
			return p.right=root.right;
	}
	if(root.right==null){
		BinarySearchTree p=getParent(root);
		if(p.left==root)
			return p.left=root.left; //return root=root.right
		else if(p.right==root)
			return p.right=root.left;
	}
	if(root.left==null){
		BinarySearchTree p=getParent(root);
		if(p.left==root)
			return p.left=root.right; //return root=root.right
		else if(p.right==root)
			return p.right=root.right;
	}
	BinarySearchTree p=getParent(root);
		if(p.left==root)
			return p.left=deleteMinimum(root.right);//return root=root.right
		else
			return p.right=deleteMinimum(root.right);
}
private BinarySearchTree getParent(BinarySearchTree node){
	BinarySearchTree p=this;
	if(p==node)
		return null;	//there's no parent
	if(p.left==node || p.right==node)
		return p;
	if(p.left!=null)
		p=p.left.getParent(node);
	if(p.right!=null)
		p=p.right.getParent(node);
	return p;
}*/

/*private BinarySearchTree deleteMinimum(BinarySearchTree root){
	if(root==null)
		return root;
	if(root.left==null){
		BinarySearchTree temp=root;
		root=root.right;
		return temp;
	}
	if(root.left.left==null && root.left.right==null){
		BinarySearchTree temp=root;
		root=root.left;
		return temp;
	}
	return deleteMinimum(root.left);
}*/

public static void main(String[] args) {

	BinarySearchTree treeA=new BinarySearchTree(3);
	treeA=treeA.insert(9);
	treeA=treeA.insert(2);
	treeA=treeA.insert(8);
	treeA=treeA.insert(6);
	treeA=treeA.insert(4);
	treeA=treeA.insert(10);
	treeA=treeA.insert(11);
	treeA=treeA.insert(56);
	//treeA.inOrder();
	System.out.println(treeA);
	treeA.delete(4);
	System.out.println(treeA);
	//System.out.println(treeA.search(57));


}
}

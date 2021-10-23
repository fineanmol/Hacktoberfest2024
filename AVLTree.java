/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//package tree;

/**
 *
 * @author Zohaib Hassan Soomro
 */
public class AVLTree {

	private int key,height;
	private AVLTree left,right;
	public static final AVLTree NIL=new AVLTree();

	public AVLTree(int key){
		this.key=key;
		left=right=NIL;
	}
	private AVLTree(){
		left=right=this;
		height=-1;
	}
	private AVLTree(int key,AVLTree left,AVLTree right){
		this.key=key; this.left=left;  this.right=right;
		height= 1 + Math.max(left.height,right.height);
	}
	public  int size(){
		if(this==NIL)
			return 0;
		return 1 + left.size() +right.size();
	}

	public String toString(){
		if(this==NIL)
			return "";
		return left+" "+key+" "+right;
	}

	public boolean add(int key){
		int oldSize=size();
		grow(key);
		return size()>oldSize;
	}
	public AVLTree grow(int key){
		if(this==NIL)
			return new AVLTree(key);
		if(key==this.key) return this;  //avoid key duplication
		if(key<this.key) left=left.grow(key);
		else
			right=right.grow(key);
		rebalance();
		height= 1 + Math.max(left.height,right.height);
		return this;
	}
	private void rebalance(){
		if (right.height>left.height+1) {
			if(right.left.height >right.right.height)
				right.rotateRight();
			rotateLeft();
		}
		else if (left.height>right.height+1) {
			if(left.right.height > left.left.height)
				left.rotateLeft();
			rotateRight();
		}
	}

	public void rotateRight(){
		right=new AVLTree(key,left.right,right);
		key=left.key;
		left=left.left;
	}
	public void rotateLeft(){
		left=new AVLTree(key,left,right.left);
		key=right.key;
		right=right.right;
	}

    public static void main(String[] args) {
    	AVLTree tree=new AVLTree(4);
    	tree.add(3);
    	tree.add(13);
    	tree.add(11);
    	tree.add(9);
    	tree.add(45);
    	tree.add(5);
    	System.out.println(tree.height);
    	System.out.println(tree);
	}
}

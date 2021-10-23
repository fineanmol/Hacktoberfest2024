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
public class BinaryTree {

Object root;
BinaryTree left, right;

BinaryTree(Object root) {
    this.root = root;
}

BinaryTree(Object root, BinaryTree left, BinaryTree right) {
    this.root = root;
    this.left = left;
    this.right = right;
}

//in-order traversal of  Binary Tree
@Override
public String toString() {
    String buf = "";
    if (left != null) 
        buf += left + ",";    // or  buf+=left.toString()+","
    
    buf += root;

    if (right != null) 
        buf += "," + right;    // or  buf+=left.toString()+","
    
    return buf;
}

//pre-order traversal of  Binary Tree
public String preOrder() {
    String buf = "";
    buf += root;
    if (left != null) 
        buf += "," + left.preOrder();   
    
    if (right != null) 
        buf += "," + right.preOrder();    
    
    return buf;
}

//post-order traversal of  Binary Tree
public String postOrder() {
    String buf = "";
    if (left != null) 
        buf += left.postOrder() + ",";    
    
    if (right != null) 
        buf +=right.postOrder()+",";   
    buf+=root;
    return buf;
}

public boolean isLeaf(){
	if(left==null && right==null)
		return true;
	return false;
}
public int size(){
	if(root==null) return 0;
	if(left==null && right==null) return 1;
	if(left==null)
		return 1+right.size();
	if(right==null)
		return 1+left.size();
	return 1+left.size()+right.size();
}

public int height(){
	if(root==null) return -1;
	if(left==null && right==null) return 0;
	int lefts=0,rights=0;
	if(left!=null)
		lefts= 1+left.height();
	if(right!=null)
		rights= 1+right.height();
	return (lefts>rights) ? lefts : rights;
}
public boolean contains(BinaryTree node){
	if(node.root.equals(root))   // if(node.root==root)
		return true;
	if(left!=null){
		if(node==left)
			return true;
		left.contains(node);
	}
	if(right!=null){
		if(node==right)
			return true;
		right.contains(node);
	}
	return false;
}
/*
public boolean contains(BinaryTree node){
	if(this.toString().contains(node.toString()))
		return true;
	return false;
}
*/

/*
Sir's method
public boolean contains(Object obj){
	if(root==object)
		return true;
	boolean contained=false;
	if(left!=null){
		if(left.toString().contains(obj.toString()))
			return true;
		contained=left.contains(obj);
	}
	if(right!=null){
		if(right.toString().contains(obj.toString()))
			return true;
		contained=right.contains(node);
	}
	return contained;
}
*/


public static void main(String[] args) {
	//level wise tree nodes spacing(b/w lines of code)

	//leaf nodes  //lower level
	BinaryTree treeG=new BinaryTree("G");
	BinaryTree treeH=new BinaryTree("H");
	BinaryTree treeI=new BinaryTree("I");
	BinaryTree treeJ=new BinaryTree("J");

	//2nd lower level
	BinaryTree treeD=new BinaryTree("D",treeG,treeH);
	BinaryTree treeE=new BinaryTree("E");
	BinaryTree treeF=new BinaryTree("F",treeI,treeJ);

	BinaryTree treeB=new BinaryTree("B",treeD,treeE);
	BinaryTree treeC=new BinaryTree("C",treeF,null);

	BinaryTree treeA=new BinaryTree("A",treeB,treeC);

	System.out.println(treeA.postOrder());
	System.out.println(treeA.size());
	System.out.println(treeA.isLeaf());
	System.out.println(treeA.height());
	System.out.println(treeG.contains(treeB));

}
}

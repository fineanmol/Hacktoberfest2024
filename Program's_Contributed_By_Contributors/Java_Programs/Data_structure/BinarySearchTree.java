
/*
Questions in this File :-
1. build a BST 
2. inOrder Traversal of BST
3. search a Node in BST
4. delete a Node in BST
5. print all Nodes in inclusive Range in a BST 
6. print all rootToleaf Path of BST
7. Min value
8. Max Value
*/


import java.util.*;

class Node {
    int data;
    Node left;
    Node right;

    Node(int data) {
        this.data = data;
    }
}

public class Main {
    public static void main(String[] args) {

        int[] nodes = { 5, 1, 3, 4, 2, 7 };
        int[] nodes2 = { 8, 5, 3, 1, 4, 6, 10, 11, 14 };
        Node root = null;

// Build Tree

        // for (int i = 0; i < nodes.length; i++) {
        // root = BinarySearchTree.insertNode(root, nodes[i]);
        // }
        // BinarySearchTree.inOrder(root);


// Search in BST

        // boolean ans = BinarySearchTree.searchBST(root, 10);
        // if (ans) {
        // System.out.println("Found");
        // } else {
        // System.out.println("Not Found");
        // }


// Delete in BST

        // BinarySearchTree.deleteNode(root, 3);
        // System.out.println();
        // BinarySearchTree.inOrder(root);

        for(int i : nodes2) {
            root = BinarySearchTree.insertNode(root, i);
        }

        BinarySearchTree.inOrder(root);
        System.out.println();

// print in Range we need new Tree thats why Nodes2 

        // List<Integer> l = new ArrayList<>();
        // List<Integer> ans = BinarySearchTree.printInRange(root, 6, 10, l);
        // for (int i : ans) {
        //     System.out.print(i + " ");
        // }


// root to leaf path we need new Tree thats why Nodes2

            List<List<Integer>> finalAns = new ArrayList<>();
            List<Integer> l = new ArrayList<>();

            finalAns =  BinarySearchTree.rootToLeafPath(root,l,finalAns);
            for(int i=0;i<finalAns.size();i++){
                System.out.print(i+1 + " Path :- ");
                for (int j = 0; j < finalAns.get(i).size(); j++) {
                    System.out.print(finalAns.get(i).get(j) + " ");
                }
                System.out.println();
            }


// Min value     
       System.out.println("min value: " + BinarySearchTree.minValue(root));
// Max value
       System.out.println("max value: " + BinarySearchTree.maxValue(root));
            
    }
}

class BinarySearchTree {

// 1. 

    public static Node insertNode(Node root, int value) {
        if (root == null) {
            Node temp = new Node(value);
            return temp;
        }
        if (root.data > value) {
            root.left = insertNode(root.left, value);
        }
        if (root.data < value) {
            root.right = insertNode(root.right, value);
        }
        return root;
    }

//2. 

    public static void inOrder(Node root) {
        if (root == null) {
            return;
        }
        inOrder(root.left);
        System.out.print(root.data + " ");
        inOrder(root.right);
    }


//3.

    public static boolean searchBST(Node root, int value) {
        if (root == null) {
            return false;
        }
        boolean rightSubTree = false;
        boolean leftSubTree = false;

        if (value > root.data) {
            rightSubTree = searchBST(root.right, value);
        }
        else if (value < root.data) {
            leftSubTree = searchBST(root.left, value);
        } else {
            return true;
        }

        if (leftSubTree || rightSubTree) {
            return true;
        }
        return false;

    }


//4.

    public static Node deleteNode(Node root, int value) {
        if(root == null){
            return null;
        }
        if (root.data > value) {
            root.left = deleteNode(root.left, value);
        } else if (root.data < value) {
            root.right = deleteNode(root.right, value);
        } else {
// 0 child
            if (root.left == null && root.right == null) {
                return null;
            }

// 1 child
// left child null            
            if (root.left == null) {
                return root.right;
            }
// right child null                
            else if (root.right == null) {
                return root.left;
            }
// 2 child
//  for node having 2 child then copy the inOrderSuccessor node data or inOrder Predecessor node data to node u have to delete this way you have two node with same value
// now you have to delete the 2 node of same value
// that's why deleteNode function is run recursively till one of the upper 2 conditions we get either 1 child or 0 child and if there is 2 child
// we just copy the value of inOrderSuccessor and move to right or inOrderPredecessor and move to left.
            else {
                Node temp = inOrderSuccessor(root.right);
                root.data = temp.data;
                root.right = deleteNode(root.right, temp.data);
            }
        }
        return root;
    }
// same as minValue function but only difference is first right then left till null for finding inOrderSuccessor
    public static Node inOrderSuccessor(Node root) {
        while (root.left != null) {
            root = root.left;
        }
        return root;
    }

// same as maxValue function but only difference is first left then right till null for finding inOrderPredecessor
    public static Node inOrderPredecessor(Node root){
        while(root.right!=null){
            root = root.right;
        }
        return root;
    }


//5.

    public static List<Integer> printInRange(Node root, int x, int y, List<Integer> l) {
        if (root == null) {
            return l;
        }

        if (root.data >= x && root.data <= y) {
            printInRange(root.left, x, y, l);
            l.add(root.data);
            printInRange(root.right, x, y, l);
        } else if (root.data > y) {
            printInRange(root.left, x, y, l);
        } else { // root.data < x
            printInRange(root.right, x, y, l);
        }
        return l;
    }



//6. 

    public static List<List<Integer>> rootToLeafPath(Node root, List<Integer> l, List<List<Integer>> finalAns){
        if(root == null){
            return finalAns;
        }

        l.add(root.data);
        rootToLeafPath(root.left, l,finalAns);
        rootToLeafPath(root.right, l,finalAns);

        if(root.left== null && root.right == null){
            finalAns.add(new ArrayList<>(l));
        }
        l.remove(l.size()-1);

        return finalAns;

    }

//7.

    public static int minValue(Node root){
        if(root == null){
            return Integer.MAX_VALUE;
        }

        int res = root.data;
        int leftNode = minValue(root.left);

        if(res > leftNode){
            res = leftNode;
        }
        return res;

    }

//8.

    public static int maxValue(Node root){
        Node temp = root;
        while(temp.right!=null){
            temp = temp.right;
        }
        return temp.data;
    }
}
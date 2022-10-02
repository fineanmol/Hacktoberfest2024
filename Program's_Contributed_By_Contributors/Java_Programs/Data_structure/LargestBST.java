/*
  QUE: Size of Largest BST in Binary Tree
  
  Time Complexity: O(N^2)
    Space Complexity: O(N)
    
    where 'N' is the total number of nodes in the binary tree.
*/

import java.util.*; 

public class LargestBST {
    public static boolean isBST(TreeNode< Integer > root, int min, int max)
    {
        if (root == null)
        {
            return true;
        }

        if (root.data < min || root.data > max)
        {
            return false;
        }

        return isBST(root.left, min, root.data - 1) && 
               isBST(root.right, root.data + 1, max);
    }

    public static int size(TreeNode < Integer > root)
    {
        if (root == null)
        {
            return 0;
        }
        
        return 1 + size(root.left) + size(root.right);
    }

    public static int largestBST(TreeNode < Integer > root) {
        // Current Subtree is BST.
        if (isBST(root, Integer.MIN_VALUE, Integer.MAX_VALUE) == true)
        {
            return size(root);
        }
        
        // Find largest BST in left and right subtrees.
        return Math.max(largestBST(root.left), largestBST(root.right));
    }
}

//Approach
// Brute Force
// We can make every node of the binary tree as the root node BST and check whether it is a BST or not. 

 

// The algorithm will be-

// We will start from the root of the binary tree and do the inorder traversal using recursion.
// For the current node ‘ROOT', we will do the following-
// If it is the root of a valid BST, we return its size.
// Else, we will find the largest BST in left and right subtrees.
// Time Complexity
// O(N^2), where ‘N’ denotes the number of nodes in the binary tree.

 

// As for every node of the binary tree, we are checking whether it is a BST or not in O(N) time. So, the total time complexity will be O(N^2).

// Space Complexity
// O(N), where ‘N’ denotes the number of nodes in the binary tree.

 

// As the maximum height of the binary tree can be ‘N’, the space complexity of the recursion stack will be O(N).
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    
    int i=0;
    int element(TreeNode root, int k) {
        if(root == null)
        return -1;
        
        
        int left = element(root.left, k);
        
        if(left != -1)
        return left;
        
        i++;
        if(i == k)
        return root.val;
        
        return element(root.right, k);
    }
    
    public int kthSmallest(TreeNode root, int k) {
        return element(root, k);
    }
}

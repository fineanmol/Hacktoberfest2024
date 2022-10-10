import java.util.*;

//  Definition for a binary tree node.
class TreeNode {
      int val;
      TreeNode left;
      TreeNode right;
      TreeNode() {}
      TreeNode(int val) { this.val = val; }
      TreeNode(int val, TreeNode left, TreeNode right) {
         this.val = val;
          this.left = left;
          this.right = right;
      }
  }
 
class Solution {
    public boolean findTarget(TreeNode root, int k) {
        Set<Integer> s=new HashSet<>();
        return check(root, s, k);
    }
    
    boolean check(TreeNode root, Set<Integer> s, int sum){
        if(root==null) return false;
        
        if(s.contains(sum-root.val))
            return true;
        
        s.add(root.val);
        
        return check(root.left, s, sum) || check(root.right, s, sum);
    }
}
// Link: https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/

// Leetcode Profile: https://leetcode.com/6rud9e/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode() {}
 * TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) {
 * this.val = val;
 * this.left = left;
 * this.right = right;
 * }
 * }
 */
class Solution {
    // global variable counting no. of good pairs
    int ans = 0;

    // helper recursive function
    private ArrayList<Integer> helper(TreeNode root, int d) {
        // 0 distance if no nodes exist
        if (root == null) {
            ArrayList<Integer> ans = new ArrayList<>();
            ans.add(0);
            return ans;
        }

        // return 1 for leaf nodes as we need to start counting from here
        if (root.left == null && root.right == null) {
            ArrayList<Integer> ans = new ArrayList<>();
            ans.add(1);
            return ans;
        }

        // get answers from left and right subtree
        ArrayList<Integer> leftAns = helper(root.left, d);
        ArrayList<Integer> rightAns = helper(root.right, d);

        // from those answers check which are good leaf node pairs i.e. sum of distance
        // from left to right <=distance
        for (int a : leftAns) {
            for (int b : rightAns) {
                if (a != 0 && b != 0 && a + b <= d) {
                    // increment our ans for such good pairs
                    ans++;
                }
            }
        }

        // calculate the value to be returned to above parent
        ArrayList<Integer> returnVal = new ArrayList<>();
        // for left subtree's ans, whichever value+1<distance then it can be summed with
        // another value from right subtree with 1 added to it for going 1 lvl above
        for (int a : leftAns) {
            // the distance should not be zero as this is the distance where node doesn't
            // exist
            if (a != 0 && a + 1 < d) {
                // add the values in our list which are allowed to go to above level
                returnVal.add(a + 1);
            }
        }

        // for right subtree's ans, whichever value+1<distance then it can be summed
        // with another value from left subtree with 1 added to it for going 1 lvl above
        for (int b : rightAns) {
            // the distance should not be zero as this is the distance where node doesn't
            // exist
            if (b != 0 && b + 1 < d) {
                // add the values in our list which are allowed to go to above level
                returnVal.add(b + 1);
            }
        }

        // return these values for above levels
        return returnVal;
    }

    public int countPairs(TreeNode root, int distance) {
        helper(root, distance);
        return ans;
    }
}

// For more solutions separated topic wise and EXPLAINED LINE BY LINE, checkout
// this github repository
// https://github.com/shubhamrawat090/Leetcode-GFG-Questions
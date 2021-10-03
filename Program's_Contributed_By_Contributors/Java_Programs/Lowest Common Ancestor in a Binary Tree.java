//https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1#
class Tree
{
    Node res;
	Node lca(Node root, int n1,int n2)
	{
	    res = null;
		helper(root, n1, n2);
		return res;
	}
	boolean helper(Node root, int n1, int n2) {
	    if(root == null) return false;
	    boolean left = helper(root.left, n1, n2);
	    boolean right = helper(root.right, n1, n2);
	    boolean current = false;
	    if(root.data == n1 || root.data == n2) current = true;
	    if(left & right || current && left || current && right) {
	        this.res = root;
	        return false;
	    }
	    return left || right || current;
	}
}
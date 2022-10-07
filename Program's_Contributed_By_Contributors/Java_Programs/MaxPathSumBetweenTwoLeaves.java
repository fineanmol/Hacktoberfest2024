class Node {
	int data;
	Node left, right;
	Node(int item) {
		data = item;
		left = right = null;
	}
}

class Res {
	int val;
}

class BinaryTree {
	static Node root;
	Node setTree(Node root){
	Node temp = new Node(0);
	if(root.right==null){
		root.right=temp;
	}
	else{ 
		root.left=temp;
	}
	return root;
	}

	int maxPathSumUtil(Node node, Res res) {
		if (node == null)
			return 0;
		if (node.left == null && node.right == null)
			return node.data;
		int ls = maxPathSumUtil(node.left, res);
		int rs = maxPathSumUtil(node.right, res);

		if (node.left != null && node.right != null) {
			res.val = Math.max(res.val, ls + rs + node.data);
			return Math.max(ls, rs) + node.data;
		}
		return (node.left == null) ? rs + node.data
				: ls + node.data;
	}

	int maxPathSum(Node node)
	{
		Res res = new Res();
		res.val = Integer.MIN_VALUE;
		if(root.left==null || root.right==null){
			root=setTree(root);
		}
		maxPathSumUtil(root, res);
		return res.val;
	}

	public static void main(String args[]) {
		BinaryTree tree = new BinaryTree();
		tree.root = new Node(-11);
		tree.root.left = new Node(9);
		tree.root.right = new Node(3);
		tree.root.left.left = new Node(-2);
		tree.root.left.right = new Node(8);
		tree.root.left.left.left = new Node(10);
		tree.root.left.left.right = new Node(6);
		tree.root.right.left = new Node(1);
		tree.root.right.right = new Node(4);
		tree.root.right.right.right = new Node(2);
		tree.root.right.right.right.left = new Node(0);
		tree.root.right.right.right.right = new Node(-12);
		tree.root.right.right.right.right.left = new Node(21);
		System.out.println("Max pathSum of the given binary tree is "
				+ tree.maxPathSum(root));
	}
}
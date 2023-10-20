package practical17.Program

// question link : https://leetcode.com/problems/delete-node-in-a-bst/description/
class Solution {

    //1.reach the given node using recursion,if not found just return
    public TreeNode deleteNode(TreeNode root, int val) {
			if(root==null)
				return root;

            
			if(val==root.val)
			{//2. After found, there are 4 conditions
                    
                //2.1 cur node have both left & ryt nodes.  
				if(root.left!=null && root.right!=null)
				{
					
                    /*concept : take ryt node's left subtree,
                                connect it to left node's ryt most node
                                connect the updated left node to ryt node's left (i.e.. ryt.left=left)
                                and return the updated ryt node. (deleting the cur node)
                    */ 
					
					TreeNode ryt=cleft(root.left,root.right);
					return ryt;
				}

                //2.2 have only ryt node
				else if(root.left==null && root.right!=null)
				{
					return root.right;
				}

                //2.3 have only left node
				else if(root.left!=null && root.right==null)
				{
					return root.left;
				}

                //2.4 have no child nodes.
				else
				{
					return null;
				}
			}

			if(val<root.val)
			{
				root.left=deleteNode(root.left,val);
				return root;
			}
			else
			{
				root.right=deleteNode(root.right,val);
				return root;
			}
    }

    //cleft() -> does insert() func and connect the updated left to (ryt.left)
    TreeNode cleft(TreeNode left,TreeNode ryt)
	{
		if(ryt.left==null)
		{
			ryt.left=left;
			return ryt;
		}
		TreeNode temp=ryt.left;
		ryt.left=insert(left,temp);
		return ryt;
		
	}

    //insert() -> connect ryt node's left subtree(temp) to rytmost of left node and return the updated left node
    TreeNode insert(TreeNode root,TreeNode temp)
	{
		if(root==null)
			return temp;
		
		root.right=insert(root.right,temp);

		return root;
	}
	
	

}
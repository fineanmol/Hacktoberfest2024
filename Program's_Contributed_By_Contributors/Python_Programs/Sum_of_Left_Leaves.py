# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    # def sumOfLeftLeaves(self, root):
    #     """
    #     :type root: TreeNode
    #     :rtype: int
    #     """
    #     if root is None:
    #         return 0
    #     if root.left is not None:
    #         if root.left.left is None and root.left.right is None:
    #             return root.left.val + self.sumOfLeftLeaves(root.right)
    #     return self.sumOfLeftLeaves(root.left) + self.sumOfLeftLeaves(root.right)

    def sumOfLeftLeaves(self, root):
        stack = [root]
        res = 0
        while len(stack) > 0:
            curr = stack.pop(0)
            if curr is not None:
                if curr.left is not None:
                    if curr.left.left is None and curr.left.right is None:
                        res += curr.left.val
                stack.insert(0, curr.right)
                stack.insert(0, curr.left)
        return res
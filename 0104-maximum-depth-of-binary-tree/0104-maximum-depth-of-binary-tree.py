# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def maxDepth(self, root):
        if not root:
            return 0
        _left=self.maxDepth(root.left)
        _right=self.maxDepth(root.right)

        return max(_left, _right)+1
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        
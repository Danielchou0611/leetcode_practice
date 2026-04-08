# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def goodNodes(self, root):
        return self.dfs(root, -1000000)
        """
        :type root: TreeNode
        :rtype: int
        """
        
    def dfs(self, root, path_max):
        if root==None:
            return 0
        if root.val>=path_max:
            return 1+self.dfs(root.left, root.val)+self.dfs(root.right, root.val)
        else:
            return self.dfs(root.left, path_max)+self.dfs(root.right, path_max)
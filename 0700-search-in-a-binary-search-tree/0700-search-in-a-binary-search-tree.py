# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def searchBST(self, root, val):
        cur=root
        while cur!=None:
            if cur.val < val:
                cur=cur.right
            elif cur.val > val:
                cur=cur.left
            else:
                return cur
        return None



        """
        :type root: Optional[TreeNode]
        :type val: int
        :rtype: Optional[TreeNode]
        """
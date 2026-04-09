#使用內部函式(封裝)
class Solution(object):
    def leafSimilar(self, root1, root2):
        def leaf(node):
            if not node: return []
            if not node.left and not node.right: return [node.val]  #回傳list, 後面可以相加:[3]+[4]=[3,4]
            return leaf(node.left)+leaf(node.right)
        return leaf(root1)==leaf(root2)

        """
        :type root1: Optional[TreeNode]
        :type root2: Optional[TreeNode]
        :rtype: bool
        """
        
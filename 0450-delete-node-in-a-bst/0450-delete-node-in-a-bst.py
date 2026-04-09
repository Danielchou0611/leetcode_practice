#delete node:找右子樹最小或左子樹最大
class Solution(object):
    def deleteNode(self, root, key):
        if not root:
            return None
        if key>root.val:
            root.right=self.deleteNode(root.right, key)
        elif key<root.val:
            root.left= self.deleteNode(root.left, key)
        else:   #找到要刪掉的節點
            if not root.left:       #無左子樹
                return root.right   
            if not root.right:      #無右子樹
                return root.left
            
            min_node= self.getmin(root.right)      #找右子樹最小
            root.val=min_node.val
            root.right=self.deleteNode(root.right, min_node.val)    #將所捕的節點刪掉
        return root
    def getmin(self, node): 
        while node.left:
            node=node.left
        return node

        """
        :type root: Optional[TreeNode]
        :type key: int
        :rtype: Optional[TreeNode]
        """
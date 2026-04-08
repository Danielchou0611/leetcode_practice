# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def longestZigZag(self, root):
        self.max_len=0
        self.dfs(root.left, 0, 1)   #root往左邊
        self.dfs(root.right, 1, 1)  #root往右邊
        return self.max_len
        # return max(self.dfs(root.left, 0), self.dfs(root.right, 1))   #不可這樣寫,因為這樣直接鎖定最大值包含root
    def dfs(self, root, judge, length):      #judge=0代表走左,judge=1代表走右
        if not root:
            return 
        self.max_len=max(self.max_len, length)
        self.dfs(root.left, 0, length+1 if judge else 1)        #往左邊走或是重新計算往右邊的path
        self.dfs(root.right, 1, length+1 if not judge else 1)   #往右邊走或是重新計算往左邊的path
       

        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        
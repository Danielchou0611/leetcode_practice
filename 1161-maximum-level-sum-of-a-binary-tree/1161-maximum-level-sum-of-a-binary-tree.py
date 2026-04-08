# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def maxLevelSum(self, root):
        max_sum=float('-inf')       #level總和可能為負的
        level, level_ans=1,1
        queue=deque()
        queue.append(root)

        while queue:
            level_len=len(queue)
            regis_sum=0
            for i in range(level_len):      #套用199題找最每個level最右邊的解法
                temp=queue.popleft()
                regis_sum+=temp.val
                if temp.left:
                    queue.append(temp.left)
                if temp.right:
                    queue.append(temp.right)
            if regis_sum > max_sum:         #for迴圈跳出來後必定是此level最後一個node
                level_ans=level
                max_sum=regis_sum
            level+=1
        return level_ans
            

        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        
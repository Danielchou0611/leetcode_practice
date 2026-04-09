#key:index是否為此level的長度-1
from collections import deque       #deque是雙端queue
class Solution(object):
    def rightSideView(self, root):
        if not root:        #看tree是否為空
            return []
        ans=[]
        queue=deque()
        queue.append(root)  #先將第一個節點加進
        while queue:
            level_len=len(queue)
            for i in range(level_len):
                temp=queue.popleft()    #最前端
                if i==level_len-1:
                    ans.append(temp.val)
                if temp.left:
                    queue.append(temp.left)
                if temp.right:
                    queue.append(temp.right)
        return ans
    
        """
        :type root: Optional[TreeNode]
        :rtype: List[int]
        """
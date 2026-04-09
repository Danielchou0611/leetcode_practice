from collections import deque
class Solution(object):
    def nearestExit(self, maze, entrance):
        queue=deque([(entrance[0], entrance[1], 0)])    #把tuple存入dqeue中,分別代表row, col, count,tuple:用小括號(),跟list類似但不可修改內容
        maze[entrance[0]][entrance[1]]='+'              #起點設為封閉
        row, col=len(maze), len(maze[0])                # m*n maze
        while queue:                                    #BFS
            r,c,step=queue.popleft()                    #將tuple pop出來
            near=[(r-1, c), (r+1, c), (r, c-1), (r, c+1)]   #上下左右
            for i, j in near:
                if i>=0 and j>=0 and i<row and j<col and maze[i][j]=='.':   #檢查是否在範圍maze內
                    if i==0 or j==0 or i==row-1 or j==col-1:                #如果到了四邊界之一就代表走到出口,
                        return step+1
                    queue.append((i,j,step+1))                              #將鄰近四點(合法可走)加入queue中
                    maze[i][j]='+'                                          #走過的點視為封閉,因為可能會造成重複探索
        return -1
        

        """
        :type maze: List[List[str]]
        :type entrance: List[int]
        :rtype: int
        """
        
#test
p=Solution()
maze = [["+","+",".","+"],[".",".",".","+"],["+","+","+","."]]
entrance = [1,0]
p.nearestExit(maze, entrance)
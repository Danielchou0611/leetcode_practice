#hard solution
from collections import defaultdict
class Solution(object):
    def equalPairs(self, grid):         #tuple是一種sequence,跟List很像，但tuple是不可變的(immutable),並用小括號表示
        dic=defaultdict(int)            #利用tuple當dictionary的key，因tuple是immutable
        output=0
        for row in grid:
            dic[tuple(row)]+=1          #將每一列轉成tuple並統計出現次數
        for i in range(len(grid)):      #len(grid)==len(grid[0])==3
            col=[]
            for j in range(len(grid)):
                col.append(grid[j][i])
            output+=dic[tuple(col)]     #利用tuple(col)當作key去查dic字典，因上面已經有出現次數，所以>=0
        return output
            

class Solution(object):
    def equalPairs(self, grid):
        output=0
        grid_trans=[list(col) for col in zip(*grid)]    #將矩陣轉置,*grid把grid每一列變成一個獨立變數並傳給zip(),zip()打包對應元素
        # print(len(grid_trans))
        for row in grid:
            for col in grid_trans:
                if row==col:
                    output+=1
        return output

        """
        :type grid: List[List[int]]
        :rtype: int
        """


class Solution(object):
    def findCircleNum(self, isConnected):
        n = len(isConnected)
        if n==1:
            return 1
        visti_list=set()
        count=0
        for city in range(n):
            if city not in visti_list:    #0,1,2,3...
                count+=1
                self.dfs(city, isConnected, visti_list)
        return count
    
    def dfs(self, city, isConnected, visit_list):
        visit_list.add(city)                                #每次iteration後visit_list會增加city
        for neighbor, edge in enumerate(isConnected[city]): #enumerate可以同時獲得index跟value
            if edge and neighbor not in visit_list:         #檢查是否有邊存在且沒visit過
                self.dfs(neighbor, isConnected, visit_list) 
            
        """
        :type isConnected: List[List[int]]
        :rtype: int
        """
    

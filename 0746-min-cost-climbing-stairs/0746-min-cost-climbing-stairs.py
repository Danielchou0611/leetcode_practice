class Solution(object):
    def minCostClimbingStairs(self, cost):
        dp=[0]*len(cost)        
        dp[0]=cost[0]
        dp[1]=cost[1]
        for i in range(2,len(cost)):
            dp[i]=cost[i]+min(dp[i-1],dp[i-2])  #依照前面較小的累加
        return min(dp[-1], dp[-2])              #最後一個跟倒數到二個比較，因為倒數第二個可以走兩步到top
        

        """
        :type cost: List[int]
        :rtype: int
        """
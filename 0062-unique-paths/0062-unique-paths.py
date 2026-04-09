#2D:time:O(mn), space:(mn)
class Solution(object):
    def uniquePaths(self, m, n):
        matrix=[[1 if i==0 or j==0 else 0 for j in range(n)]for i in range(m)]
        for i in range(1, m):
            for j in range(1, n):
                matrix[i][j]=matrix[i-1][j]+matrix[i][j-1]
        return matrix[m-1][n-1]

        """
        :type m: int
        :type n: int
        :rtype: int
        """

#before take simple
# matrix = [[0 for _ in range(n)] for _ in range(m)]  #初始化二維陣列
# for i in range(0, m):
#     matrix[i][0]=1
# for i in range(0, n):
#     matrix[0][i]=1

#1D:time:O(mn), but space:(n)
class Solution(object):
    def uniquePaths(self, m, n):
        dp=[1]*n
        for _ in range(1, m):
            for j in range(1, n):
                dp[j]+=dp[j-1]
        return dp[-1]
        """
        :type m: int
        :type n: int
        :rtype: int
        """


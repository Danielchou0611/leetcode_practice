class Solution(object):
    def longestCommonSubsequence(self, text1, text2):
        row, col=len(text2)+1, len(text1)+1
        dp=[[0 for _ in range(col)]for _ in range(row)]     #兩個[]夾起來的是內圈,最右邊是最外圈
        for i in range(1, row):
            for j in  range(1, col):
                if text2[i-1]==text1[j-1]:
                    dp[i][j]=dp[i-1][j-1]+1
                else:
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1])
        return dp[row-1][col-1]

        """
        :type text1: str
        :type text2: str
        :rtype: int
        """
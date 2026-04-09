#盜賊不能搶相鄰的住家
class Solution(object):
    def rob(self, nums):
        if len(nums)==1:
            return nums[0]
        dp=[0]*len(nums)
        dp[0]=nums[0]
        dp[1]=max(dp[0], nums[1])       #要注意會有一個測資的情況
        for i in range(2, len(nums)):
            dp[i]=max(nums[i]+dp[i-2], dp[i-1])
        return dp[-1]

        """
        :type nums: List[int]
        :rtype: int
        """
        
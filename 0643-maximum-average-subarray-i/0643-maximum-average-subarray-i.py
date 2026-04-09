class Solution(object):
    def findMaxAverage(self, nums, k):
        curmax=sum(nums[:k])
        maximum=curmax
        for i in range(k, len(nums)):
            curmax=curmax+nums[i]-nums[i-k]
            maximum=max(maximum, curmax)
        return round(maximum/float(k),5)  
    
        """
        :type nums: List[int]
        :type k: int
        :rtype: float
        """
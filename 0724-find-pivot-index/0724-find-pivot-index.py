class Solution(object):
    def pivotIndex(self, nums):
        total=sum(nums)
        leftsum=0
        for i in range(len(nums)):
            if leftsum==total-nums[i]-leftsum:
                return i
            leftsum+=nums[i]
        return -1
    
        """
        :type nums: List[int]
        :rtype: int
        """
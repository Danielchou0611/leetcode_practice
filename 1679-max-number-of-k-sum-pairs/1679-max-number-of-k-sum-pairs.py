class Solution(object):
    def maxOperations(self, nums, k):
        left, right=0, len(nums)-1
        count=0
        nums=sorted(nums)
        while left<right:
            sum=nums[left]+nums[right]
            if sum==k:
                count+=1
                left+=1
                right-=1
            elif sum>k:
                right-=1
            else:
                left+=1
        return count


        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        
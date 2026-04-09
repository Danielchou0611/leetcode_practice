class Solution(object):
    def findPeakElement(self, nums):
        return self.binary_search(nums, 0, len(nums)-1)
    def binary_search(self, nums, left, right):
        if right-left==0:
            return left
        if right-left==1:
            return right if nums[right]>nums[left] else left
        mid=(left+right)//2
        if nums[mid]>nums[mid-1] and nums[mid]>nums[mid+1]:
            return mid
        return self.binary_search(nums, mid+1, right) if nums[mid+1]>nums[mid] else self.binary_search(nums, left, mid-1)


        """
        :type nums: List[int]
        :rtype: int
        """
        
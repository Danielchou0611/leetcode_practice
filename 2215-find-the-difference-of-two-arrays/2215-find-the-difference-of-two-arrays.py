class Solution(object):
    def findDifference(self, nums1, nums2):
        matrix_1=set(nums1)
        matrix_2=set(nums2)
        
        return [list(matrix_1-matrix_2), list(matrix_2-matrix_1)]      #set可以直接做運算
        # &:交集,|:聯集但不重複選,-:差集,^:反交集(取不重疊的部分)
        
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[List[int]]
        """
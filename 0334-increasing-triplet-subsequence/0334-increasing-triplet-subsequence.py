#better method
class Solution(object):
    def increasingTriplet(self, nums):
        num1=num2=float('inf')  #無限大
        for number in nums:
            if number<=num1:
                num1=number
            elif number<=num2:
                num2=number
            else:
                return True
        return False

#first written
# class Solution(object):
#     def increasingTriplet(self, nums):
#         num1=nums[0]
#         num2=float('-inf')
#         for i in range(1,len(nums)):
#             if nums[i]>num1:
#                 if num2==float('-inf'):
#                     num2=nums[i]
#                 elif nums[i]>num2:
#                     return True
#                 elif nums[i]<num2:
#                     num2=nums[i]
#             else:
#                 num1=nums[i]
              
#         return False 
            

        """
        :type nums: List[int]
        :rtype: bool
        """
        
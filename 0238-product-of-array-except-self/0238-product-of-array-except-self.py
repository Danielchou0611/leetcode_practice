#prefix product:前綴(從陣列開頭到某個位置之前的所有元素乘積)(自己左邊所有數字的乘積)
#suffix product:後綴(從陣列末尾到某個位置之後的所有元素乘積)(自己右邊所有數字的乘積)
#Hint:建立prefix array
class Solution(object):
    def productExceptSelf(self, nums):
        n = len(nums)
        result=[1]*n
        prefix, suffix=1, 1
        for i in range(n):
            result[i]*=prefix
            prefix*=nums[i]
        for i in range(n-1, -1, -1):        #range(起始值, 結束值(不包含),每次前進長度)
            result[i]*=suffix
            suffix*=nums[i]
        return result

        """
        :type nums: List[int]
        :rtype: List[int]
        """
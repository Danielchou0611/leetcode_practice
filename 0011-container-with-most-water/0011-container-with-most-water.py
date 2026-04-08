#key: 找出左邊跟右邊,且水不會超過比較矮的那邊
class Solution(object):
    def maxArea(self, height):
        left, right=0, len(height)-1
        area=0
        while left<right:  #總是移動較矮的那邊
            high=min(height[left], height[right])   #面積的高要取矮的
            area=max(area, high*(right-left))

            if height[left]<height[right]:      #一直尋找更大的height
                left+=1
            else:
                right-=1
        return area 
        
        """
        :type height: List[int]
        :rtype: int
        """
        
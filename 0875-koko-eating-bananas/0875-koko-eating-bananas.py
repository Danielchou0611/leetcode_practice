#迴圈版本
class Solution(object):
    def minEatingSpeed(self, piles, h):
        left, right=1, max(piles)
        min_result=right
        while left <= right:
            mid = (left+right)//2
            count_h=0
            for i in range(len(piles)):
                count_h+=((piles[i]+mid-1)//mid)        #(a+b-1)//b,為ceiling的方法, 7/3=3
            if count_h<=h:      #時數太小,往左邊找更小被除數
                min_result=mid
                right=mid-1
            else:
                left=mid+1
        return min_result
    
        """
        :type piles: List[int]
        :type h: int
        :rtype: int
        """
#遞迴版本
class Solution(object):
    def minEatingSpeed(self, piles, h):
        return self.binary_search(1, max(piles), piles, h)
    def binary_search(self, left, right, piles, h):
        if left>right:      #終止條件
            return left     #為什麼return left,當left>right終止時,left會停留在最小可行速度
        mid = (left+right)//2
        count_h=sum((pile+mid-1)//mid for pile in piles)    
        if count_h<=h:
            return  self.binary_search(left, mid-1, piles, h)
        else:
            return self.binary_search(mid+1, right, piles, h)


#test
p=Solution()    
piles = [30,11,23,4,20]
p.minEatingSpeed(piles, 8)



       
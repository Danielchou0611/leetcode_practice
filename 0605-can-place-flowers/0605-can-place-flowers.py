class Solution(object):
    def canPlaceFlowers(self, flowerbed, n):
        i=0
        planted=flowerbed[0]
        while(i<len(flowerbed) and n!=0):
            if planted==False and flowerbed[i]==False and (i==len(flowerbed)-1 or flowerbed[i+1]==False ):
                n-=1
                planted=True
            else:
                planted=flowerbed[i]
            i+=1
        # if flowerbed[i]==False and planted==False and n!=0:
        #     n-=1
        return not n
        """
        :type flowerbed: List[int]
        :type n: int
        :rtype: bool
        """
        
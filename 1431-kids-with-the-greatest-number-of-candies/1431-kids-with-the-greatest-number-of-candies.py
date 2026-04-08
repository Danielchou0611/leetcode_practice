
class Solution(object):
    def kidsWithCandies(self, candies, extraCandies):
        greatest=max(candies)
        result=[]
        for i in candies:
            if i+extraCandies>=greatest:
                result.append(True)
            else:
                result.append(False)
        return result
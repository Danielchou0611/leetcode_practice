class Solution(object):
    def guessNumber(self, n):
        low, high= 1,n
        while True:
            mid=(high+low)>>1       #位元運算會快一些
            result=guess(mid)
            if result==0:
                return mid
            elif result==-1:
                high=mid-1
            else:
                low=mid+1

        """
        :type n: int
        :rtype: int
        You call a pre-defined API int guess(int num), which returns three possible results:
            -1: Your guess is higher than the number I picked (i.e. num > pick).
            1: Your guess is lower than the number I picked (i.e. num < pick).
            0: your guess is equal to the number I picked (i.e. num == pick).
        """
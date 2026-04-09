class Solution(object):
    def countBits(self, n):
        result=[0]*(n+1)
        for i in range(1, n+1):
            result[i]=result[i>>1]+(i&1)       #i/2的已經計算過就不用再算,i&1是看最後一碼是不是1
        return result

        """
        :type n: int
        :rtype: List[int]
        """
        
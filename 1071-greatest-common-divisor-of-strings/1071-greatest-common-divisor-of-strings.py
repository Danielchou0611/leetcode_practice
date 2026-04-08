import math
class Solution(object):
    def gcdOfStrings(self, str1, str2):
        if str1+str2 != str2+str1:  #這個條件可以檢查初步檢查兩字串是否存在公因字串
            return ""
        #len_string=math.gcd(len(str1), len(str2)),但python3才支援math.gcd
        def  gcd(len1, len2):
            while len2:
                len1,len2=len2, len1%len2
            return len1
        return str1[:gcd(len(str1), len(str2))]

        """
        :type str1: str
        :type str2: str
        :rtype: str
        """
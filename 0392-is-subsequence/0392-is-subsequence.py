class Solution(object):
    def isSubsequence(self, s, t):
        
        len_t, len_s = 0, 0
        while len_t < len(t) and len_s < len(s):
            if  s[len_s]==t[len_t]:
                len_s+=1
            len_t+=1
        return len_s==len(s)
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        
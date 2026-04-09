class Solution(object):
    def reverseWords(self, s):
        words=s.split()     #split後會回傳list
        return ' '.join(reversed(words))    #將List內順序反轉
        
        """
        :type s: str
        :rtype: str
        """
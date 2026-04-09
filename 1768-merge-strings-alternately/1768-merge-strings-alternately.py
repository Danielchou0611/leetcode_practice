class Solution(object):
    def mergeAlternately(self, word1, word2):
        i, j, count=0,0,0
        re=[]
        while i<len(word1) or j<len(word2):
            if i<len(word1):
                re.append(word1[i])
                i+=1
            if j<len(word2):
                re.append(word2[j])
                j+=1
        return ''.join(re)      #把字串列表合併成一個完整的字串，中間用''(空字串)連接
        """
        :type word1: str
        :type word2: str
        :rtype: str
        """
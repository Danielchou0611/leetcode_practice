class Solution(object):
    def reverseVowels(self, s):
        vowel=set("aeiouAEIOU")        
        s=list(s)
        i,j= 0, len(s)-1
        while(i<j):
            if s[i] in vowel and s[j] in vowel:
                s[i], s[j]=s[j], s[i]
                i+=1
                j-=1
            elif s[i] not in vowel:
                i+=1
            else:
                j-=1

        return ''.join(s)
       
        """
        :type s: str
        :rtype: str
        """    
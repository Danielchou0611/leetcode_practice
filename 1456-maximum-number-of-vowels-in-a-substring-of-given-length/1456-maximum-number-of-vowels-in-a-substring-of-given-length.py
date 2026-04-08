class Solution(object):
    def maxVowels(self, s, k):
        vowel_map=['a','e', 'i', 'o', 'u']  #建立母音set
        max_count=0
        for i in range(k):
            max_count+=(s[i] in vowel_map) 

        count=max_count
        for i in range(k, len(s)):
            count+=((s[i] in vowel_map)-(s[i-k] in vowel_map))
            max_count=max(count, max_count)
        return max_count
#想法:記每個元素所出現的數目list,並比較兩word的set是否相同
from collections import Counter     #Counter可以統計word裡字母分別出現的次數
class Solution(object):
    def closeStrings(self, word1, word2):
        count_word1=Counter(word1)
        count_word2=Counter(word2)
        #判斷裡面所包含的字母集合是否相同以及判斷字母分布, ex:'aabbccdd', 'aabbcc'在set會相同但vlaue就不一樣
        if (set(count_word1.keys())!=set(count_word2.keys())) or (sorted(count_word1.values())!=sorted(count_word2.values())):
            return False
        return True


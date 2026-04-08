# class Solution(object):
#     def uniqueOccurrences(self, arr):
#         occur=[0]*2001
#         for num in arr:
#             occur[num+1000]+=1
#         occur=[x for x in occur if x>0]     #過濾掉0次的變成最後的list
#         return (len(occur)==len(set(occur)))    #set會移到重複的次數,set不能有重複元素

from collections import Counter   #內建Counter計數
class Solution(object):
    def uniqueOccurrences(self, arr):
        count=Counter(arr)
        return len(count.values())==len(set(count.values()))
#solve without sorting
import heapq            #heapq提供heap相關操作函式
class Solution(object):
    def findKthLargest(self, nums, k):
        min_heap=[] 
        for number in nums:
            heapq.heappush(min_heap, number)    #heapq內建是minheap,如果要max_heap可以將number*(-1)即可
            if len(min_heap)>k:                 #保留前k大,如果插入元素超過k個就把最小的pop出去,最後min_heap的root就是第k大元素
                heapq.heappop(min_heap)
        return min_heap[0]      
#time complexity:O(nlogk), k為heap存的元素數量,n為nums大小
#為什麼不能push全部元素在return min_head[len(nums)-k-1],因為heap不會sorting



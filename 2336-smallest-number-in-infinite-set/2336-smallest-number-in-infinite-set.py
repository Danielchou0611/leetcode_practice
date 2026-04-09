import heapq
class SmallestInfiniteSet(object):

    def __init__(self):
        self.smallest=1
        self.add_back=[]        #最小堆,用來存回被加回來的數字
        self.in_heap=set()      #避免重複

    def popSmallest(self):      #從集合中取出並移除最小的整數
        if self.in_heap:
            small=heapq.heappop(self.add_back)
            self.in_heap.remove(small)
            return small
        self.smallest+=1        #如果沒有就把smallest傳回
        return self.smallest-1
        """
        :rtype: int
        """
        
    def addBack(self, num):     #將一個數字加回set,前提是這個數字不在set中
        if num < self.smallest and num not in self.in_heap:
            heapq.heappush(self.add_back, num)
            self.in_heap.add(num)
        """
        :type num: int
        :rtype: None
        """
        


# Your SmallestInfiniteSet object will be instantiated and called as such:
# obj = SmallestInfiniteSet()
# param_1 = obj.popSmallest()
# obj.addBack(num)
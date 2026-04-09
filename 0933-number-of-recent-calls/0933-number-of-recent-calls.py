from collections import deque
class RecentCounter(object):

    def __init__(self):
        self.q=deque()      #建立雙向queue,可以從左邊或右邊加入,也可以從左邊或右邊刪除

    def ping(self, t):
        self.q.append(t)
        while t-self.q[0]>3000:     #range是3000內,所以要刪除最舊的資料(左邊),q只保留範圍3000內的,
            self.q.popleft()
        return len(self.q)
    
        """
        :type t: int
        :rtype: int
        """
        


# Your RecentCounter object will be instantiated and called as such:
# obj = RecentCounter()
# param_1 = obj.ping(t)
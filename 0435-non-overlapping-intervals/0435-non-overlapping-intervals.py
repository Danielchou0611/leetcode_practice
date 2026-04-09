class Solution(object):
    def eraseOverlapIntervals(self, intervals):
        intervals.sort(key=lambda x:x[1])   #intervals依照結束時間排序,lambda是用來建立匿名函式的關鍵字，等同於只有一行的函式
        output=0
        endtime=intervals[0][1]
        for index in range(1,len(intervals)):
            if intervals[index][0]<endtime:
                output+=1
            else:
                endtime=intervals[index][1]
        return output
        
        """
        :type intervals: List[List[int]]
        :rtype: int
        List[List[int]] example:[[1,2],[2,3],[3,4],[1,3]]
            List[0]=[1,2]
            List[0][1]=2
            List[2]=[3,4]
        """
        
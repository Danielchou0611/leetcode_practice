class Solution(object):
    def dailyTemperatures(self, temperatures):
        result=[0]*len(temperatures)    
        stack=[]        #存放溫度的索引，且這些溫度都還沒找到更高的溫度
        for i,temp in enumerate(temperatures):  #enumerate(temperatures):同時取得列表temperatures中每個元素的index跟值,並給i及temp
            while stack and temp>temperatures[stack[-1]]:   #stack[-1]:stack(列表)頂端,迴圈找到此temp可以高於所有stack裡面的index
                index=stack.pop()
                result[index]=i-index
            stack.append(i)
        return result

        """
        :type temperatures: List[int]
        :rtype: List[int]
        """
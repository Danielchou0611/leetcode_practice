class Solution(object):
    def asteroidCollision(self, asteroids):
        result=[]
        for aster in asteroids:
            while result and aster<0<result[-1]:       #list[-1]代表取頂端元素(stack概念)
                if result[-1]<-aster:   #後面大,爆炸
                    result.pop()
                    continue            #繼續看result頂端還會不會爆炸
                elif result[-1]==-aster:    #相同top的爆炸,且現在的元素不能加入
                    result.pop()
                break                   #如果沒有continue就結束(else)
            else:           #else是對應while的,如果沒有break就執行else
                result.append(aster)
        return result
    
        """
        :type asteroids: List[int]
        :rtype: List[int]
        """
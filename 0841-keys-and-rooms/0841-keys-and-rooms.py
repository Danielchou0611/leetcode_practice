from collections import deque   #collections是python的一個module, 是容器的集合
class Solution(object):
    def canVisitAllRooms(self, rooms):
        visit=set()             #存key,用set是因為不會重複
        queue=deque([0])
        while queue:
            room=queue.popleft()
            if room in visit:
                continue
            visit.add(room)
            for index in rooms[room]:   #一個room可能含多個key
                if index not in visit:
                    queue.append(index)
        return len(visit)==len(rooms)
                
        """
        :type rooms: List[List[int]]
        :rtype: bool
        """


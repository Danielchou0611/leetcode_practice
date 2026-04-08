#solution 2:use XOR operation
from collections import Counter
class Solution(object):
    def singleNumber(self, nums):
        answer=0
        for number in nums:
            answer^=number
        return answer
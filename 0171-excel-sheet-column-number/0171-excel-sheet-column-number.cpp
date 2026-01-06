#include <iostream>
#include <string>
using namespace std;
/*
    解法ex: ZAY = (ZA)*26+Y = ((Z*26)+A)*26+Y
    time complexity: O(n)
    space complexity: O(1)
*/
class Solution
{
public:
    int titleToNumber(string columnTitle)
    {
        long long count = 0;       // long long防止溢位
        for (char c : columnTitle) // 遍歷字串
            count = count * 26 + (c - 'A' + 1);
        return count;
    }
};
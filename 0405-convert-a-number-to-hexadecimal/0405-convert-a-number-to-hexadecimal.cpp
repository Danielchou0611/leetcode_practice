#include <string>
#include <algorithm>
using namespace std;
/*
    Solution: 位元運算，建立16位元表，每次做最後4bits(n&f)，
    time complexity: O(1) -> 最多32位元
    space complexity: O(1)
*/
class Solution
{
public:
    string toHex(int num)
    {
        if (num == 0)
            return "0";
        unsigned int n = num;
        string hexchart = "0123456789abcdef";
        string result = "";
        while (n > 0)
        {
            int digit = n & 0xf; // 可保留1的部分
            result += hexchart[digit];
            n >>= 4;
        }
        reverse(result.begin(), result.end()); // 因result是用加的(add_back)，所以最後要反轉
        return result;
    }
};
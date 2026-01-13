#include <iostream>
using namespace std;
/*
    Solution: 只要石頭為4的倍數，先者必輸(回傳false)
    time complexity: O(1)
    space complexity: O(1)
*/
class Solution
{
public:
    bool canWinNim(int n)
    {
        return (n & 3) != 0; // 不為4的倍數先者就會贏，n&3相等於n%4(除4的餘數)
    }
};

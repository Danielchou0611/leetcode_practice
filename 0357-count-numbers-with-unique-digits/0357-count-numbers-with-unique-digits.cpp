#include <cmath>
class Solution
{
public:
    int countNumbersWithUniqueDigits(int n) // n代表幾位數, ex: n=2 -> 0 <= x < 100
    {
        if (n == 0)
            return 1;
        int total = 10;
        int multi = 9;
        for (int i = 2; i <= n; i++)
        {
            total += multi * (11 - i);
            multi *= (11 - i);
        }
        return total;
    }
};

/*
思路:
1位數: 0-9，共9種
2位數: _ _ ，第1位不能為0 & 第2位不能跟1位重複 -> 9*9種組合
3位數: _ _ _，第1位不能為0 & 第2位不能跟第1位重複 & 第3位不能跟前兩位重複 -> 9*9*8種組合
...and son on
*/
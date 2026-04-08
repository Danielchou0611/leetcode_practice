#include <iostream>
using namespace std;
class Solution
{
public:
    int minFlips(int a, int b, int c)
    {
        if (!a && !b && !c) // 終止條件
            return 0;
        int bit_a = a & 1, bit_b = b & 1, bit_c = c & 1, flip_count = 0; // 用&1可以直接取最後一位,比%(mod)快
        // int bit_a = a % 2, bit_b = b % 2, bit_c = c % 2;
        // bit要inverse的情況:(a,b,c)=(0,0,1) (1,1,0) (0,1,0) (1,0,0)->而(1,1,0)要反轉兩次
        if ((bit_c && !bit_a && !bit_b) || (!bit_c && (bit_b + bit_a == 1 || bit_b + bit_a == 2)))
            flip_count = bit_a + bit_b + bit_c;
        return flip_count + minFlips(a >> 1, b >> 1, c >> 1); // 用右移加速除法
    }
};
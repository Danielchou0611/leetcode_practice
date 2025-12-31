class Solution // 4的冪次方(需>0)
{
public:
    bool isPowerOfFour(int n)
    {
        return (n > 0) && ((n & (n - 1)) == 0) && (n & 0x55555555);
        // n&(n-1)==0判斷是否為2的冪次方
        // n&0x55555555確保唯一的1在偶數位(1右方的0有偶數個，且只有一個1)
    }
};
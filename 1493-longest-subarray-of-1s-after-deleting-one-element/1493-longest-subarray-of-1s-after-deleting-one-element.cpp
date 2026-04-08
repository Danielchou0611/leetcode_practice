#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int part = 0, ans = 0, cur_1sum = 0;
        bool judge = true; // 用於判斷是否有遇到0,如果沒有0就要刪掉一個1
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i])
                cur_1sum++;
            else
            {
                judge = false;
                ans = max(ans, cur_1sum + part); // 前後兩段相加比(因為可以刪掉一個0)
                part = cur_1sum;
                cur_1sum = 0;
            }
        }
        return max(ans, part + cur_1sum) - judge;
    }
};
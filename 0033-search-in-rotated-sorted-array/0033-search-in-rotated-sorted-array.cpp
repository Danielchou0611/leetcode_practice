#include <iostream>
#include <vector>
using namespace std;
/*
    使用類似binary search，切成一半後一定會有一個半邊是排序好的(遞增)
    time complexity: O(logn)
    space complexity: O(1)
*/
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size()-1, mid;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[left] <= nums[mid]) // 左邊排序好
            {
                if (target >= nums[left] && target <= nums[mid]) // target在此區間內
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else // 右邊排序好
            {
                if (target >= nums[mid] && target <= nums[right]) // target在此區間內
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return -1;
    }
};
#include <iostream>
#include <vector>
using namespace std;
/*
    Solution 1: binary search
    time complexity: O(logn)
    space complexty: O(1)
*/
class Solution
{
private:
    int start, end;

public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        this->start = -1;
        this->end = -1;
        binary_search(nums, 0, nums.size() - 1, target);
        vector<int> result;
        result.push_back(start);
        result.push_back(end);
        return result;
    }
    void binary_search(vector<int> &nums, int left, int right, int target)
    {
        if (left > right)
            return;
        int mid = left + ((right - left) >> 1); // int mid = (left + right) / 2;  一樣是取中位數，但這是為了防止overflow(因left+right可能會overflow)
        if (nums[mid] == target)
        {
            if (this->start == -1)
            {
                this->start = mid;
                this->end = mid;
            }
            else if (mid > end)
                end = mid;
            else if (mid < start)
                start = mid;
            binary_search(nums, left, mid - 1, target);
            binary_search(nums, mid + 1, right, target);
        }
        else if (nums[mid] > target)
            binary_search(nums, left, mid - 1, target);
        else
            binary_search(nums, mid + 1, right, target);
    }
};

// //    Solution 2: Solution 1 的精簡版
// class Solution
// {
// private:
//     int findbound(vector<int> &nums, int target, int isFirst)
//     {
//         int left = 0, right = nums.size() - 1;
//         int bound = -1;
//         while (left <= right)
//         {
//             int mid = left + ((right - left) >> 1); //+優先於>>
//             if (nums[mid] == target)
//             {
//                 bound = mid; // 當前位置
//                 if (isFirst) // 在mid左半部找更左邊的邊界(左邊可能還有)
//                     right = mid - 1;
//                 else // 在mid右半部找更右邊的邊界(右邊可能還有)
//                     left = mid + 1;
//             }
//             else if (nums[mid] > target)
//                 right = mid - 1;
//             else
//                 left = mid + 1;
//         }
//         return bound;
//     }

// public:
//     vector<int> searchRange(vector<int> &nums, int target)
//     {
//         int first = findbound(nums, target, true);
//         if (first == -1)
//             return {-1, -1};
//         int last = findbound(nums, target, false);
//         return {first, last};
//     }
// };

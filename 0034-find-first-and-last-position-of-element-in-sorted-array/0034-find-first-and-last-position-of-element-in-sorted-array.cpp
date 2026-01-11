//    Solution 2: Solution 1 的精簡版
class Solution
{
private:
    int findbound(vector<int> &nums, int target, int isFirst)
    {
        int left = 0, right = nums.size() - 1;
        int bound = -1;
        while (left <= right)
        {
            int mid = left + ((right - left) >> 1); //+優先於>>
            if (nums[mid] == target)
            {
                bound = mid; // 當前位置
                if (isFirst) // 在mid左半部找更左邊的邊界(左邊可能還有)
                    right = mid - 1;
                else // 在mid右半部找更右邊的邊界(右邊可能還有)
                    left = mid + 1;
            }
            else if (nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return bound;
    }

public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int first = findbound(nums, target, true);
        if (first == -1)
            return {-1, -1};
        int last = findbound(nums, target, false);
        return {first, last};
    }
};
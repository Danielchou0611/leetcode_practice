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
        int mid = (left + right) / 2;
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
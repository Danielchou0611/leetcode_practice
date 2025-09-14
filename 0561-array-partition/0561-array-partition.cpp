// key:小的盡量跟小的在同一個()裡,大的number才會有所使用,不然都被min出去
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int arrayPairSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int sum = 0;
        // for (int i = 0; i < nums.size() - 1; i += 2)
        //     sum += min(nums[i], nums[i + 1]);    其實排序後只需要加上(a,b)的a(較小)就好,min多此一舉
        for (int i = 0; i < nums.size(); i += 2)
            sum += nums[i];
        return sum;
    }
};
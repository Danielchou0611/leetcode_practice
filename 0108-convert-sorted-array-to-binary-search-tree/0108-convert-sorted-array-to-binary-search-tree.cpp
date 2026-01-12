// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
#include <vector>
using namespace std;
/*
    Solution: 不需要複雜的AVL Tree, 因為imput是ascending order
    time complexity: O(n)
    space complexity: O(n)
*/
class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return build(nums, 0, nums.size() - 1);
    }
    TreeNode *build(vector<int> &nums, int left, int right) // 類似binary search作法，每一次抓最中間的node當作parent，而左邊跟右邊的當左右子樹
    {
        if (left > right)
            return nullptr;
        int mid = left + (right - left) / 2;
        TreeNode *result = new TreeNode(nums[mid]);
        result->left = build(nums, left, mid - 1);
        result->right = build(nums, mid + 1, right);
        return result;
    }
};
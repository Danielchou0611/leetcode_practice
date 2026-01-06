#include <iostream>
using namespace std;
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

/*
    利用inorder由小到大排序的特點找出不在排序上的兩個數字
    time complexity: O(n)
    space complexity: O(h), h為樹高
*/

class Solution
{
public:
    TreeNode *prev = nullptr;
    TreeNode *first = nullptr;
    TreeNode *second = nullptr;
    void recoverTree(TreeNode *root)
    {
        // 不用先把prev設為INT_MIN，因為可能會有edge case為INT_MIN
        inorder(root);
        if (first && second) // swap value
        {
            int t = first->val;
            first->val = second->val;
            second->val = t;
        }
    }
    void inorder(TreeNode *root)
    {
        if (!root)
            return;
        inorder(root->left);
        if (prev && prev->val > root->val) // prev不為空
        {
            if (!first)
                first = prev;
            second = root; // 不加else是因為有可能會有兩個錯誤節點可能是相鄰的，如加了else就會找不到相鄰的第二個
        }
        prev = root;
        inorder(root->right);
    }
};
// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */

// key:兩層DFS，針對每個node做dfs看path_sum是否符合
#include <iostream>
using namespace std;
class Solution
{
public:
    int pathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return 0;
        return pathSum(root->left, targetSum) + pathSum(root->right, targetSum) + dfs(root, targetSum); // 第一層dfs:針對每個node看path
    }
    int dfs(TreeNode *root, long long int sum) // 因node value有可能為10^9, 而int(32bits)最多只能到+-2*10^9, 所以用long long int(64bits)可以到+-9.2*10^18
    {
        if (!root)
            return 0;
        return (root->val == sum) + dfs(root->left, sum - root->val) + dfs(root->right, sum - root->val); // 第二層dfs:看從此node往下的path是否符合, 前面回傳0或1
    }
};
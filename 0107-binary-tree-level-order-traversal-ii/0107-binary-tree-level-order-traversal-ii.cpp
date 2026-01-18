/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/*
    Solution: 利用(102題)levelorder的輸出順序，將此reverse即可
    time complexity: O(n)
    spcae complexity: O(n)
*/
class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        vector<int> tmp;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) // level order
        {
            int n = q.size();
            for (int i = 0; i < n; i++) // 將同一層的存在同一個vector
            {
                TreeNode *node = q.front();
                q.pop();
                tmp.emplace_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            ans.emplace_back(std::move(tmp)); // 使用移動的方法比較快,tmp size也會變0
            // ans.emplace_back(tmp);
            // tmp.clear();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
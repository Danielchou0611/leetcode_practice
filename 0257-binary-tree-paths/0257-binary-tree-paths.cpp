class Solution
{
public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> path;
        if (root)
            dfs(root, "", path);
        return path;
    }

private:
    void dfs(TreeNode *root, string p, vector<string> &path)
    {
        if (!root)
            return;
        if (p.empty()) // p還沒有東西
            p = to_string(root->val);
        else
            p += "->" + to_string(root->val);
        if (!root->left && !root->right)
            path.push_back(p);
            
        if (root->left)
            dfs(root->left, p, path);
        if (root->right)
            dfs(root->right, p, path);
    }
};
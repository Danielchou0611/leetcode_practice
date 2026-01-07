#include <iostream>
#include <vector>
using namespace std;
// mat[i][j] and target[i][j] are either 0 or 1.
/*
    Solution: 有可能轉0, 90, 180, 270度，嘗試不rotate,去數三種可能的rotate符合次數(符合其一即可)
    time complexity: O(n^2)
    space complexity: O(1)
*/
class Solution
{
public:
    bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target)
    {
        int n = mat.size();
        bool deg_90 = true, deg_180 = true, deg_270 = true;
        for (int i = 0; i < n; i++) // size為row的大小
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] != target[j][n - i - 1]) // 90度
                    deg_90 = false;
                if (mat[i][j] != target[n - i - 1][n - j - 1])
                    deg_180 = false;
                if (mat[i][j] != target[n - j - 1][i])
                    deg_270 = false;
            }
        }
        return deg_90 || deg_180 || deg_270 || (mat == target);
    }
};
// int main()
// {
//     Solution a;
//     vector<vector<int>> q1 = {{1, 2, 3},
//                               {4, 5, 6},
//                               {7, 8, 9}};
//     vector<vector<int>> q2 = {{1, 2, 3},
//                               {4, 5, 6},
//                               {7, 8, 9}};
//     a.findRotation(q1, q2);
//     return 0;
// }
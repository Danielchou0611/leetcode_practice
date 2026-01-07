#include <iostream>
#include <vector>
using namespace std;
/*
    Solution: 利用標註第一列跟第一行的方法，而第一行跟第一列分開處理
    time complexity: O(m*n)
    space complexity: O(1)
*/
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        bool first_row = false, first_col = false; // 紀錄第一行跟第一列是否存在0
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    if (i == 0)
                        first_row = true;
                    if (j == 0)
                        first_col = true;
                    matrix[i][0] = 0; // 利用第一行跟第一列所有元素來標註出非第一行跟第一列的元素是否有0的
                    matrix[0][j] = 0;
                }
            }
        }
        for (int j = 1; j < n; j++)
        {
            if (matrix[0][j] == 0)
                for (int i = 1; i < m; i++)
                    matrix[i][j] = 0;
        }
        for (int i = 1; i < m; i++)
        {
            if (matrix[i][0] == 0)
                for (int j = 1; j < n; j++)
                    matrix[i][j] = 0;
        }
        if (first_row)
            for (int j = 0; j < n; j++)
                matrix[0][j] = 0;
        if (first_col)
            for (int i = 0; i < m; i++)
                matrix[i][0] = 0;
    }
};
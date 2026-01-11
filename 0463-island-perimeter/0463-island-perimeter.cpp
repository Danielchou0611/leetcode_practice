#include <vector>
using namespace std;
/*
    Solution: 一個小方塊為4個邊，如果上下左右有方塊為1的話，就4-(相鄰幾個方塊為1)
    time complexity: O(m*n)
    space complexity: O(1)
*/
class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        long sum = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j])
                {
                    sum += (i == 0 || !grid[i - 1][j]);                  // 上
                    sum += (i == grid.size() - 1 || !grid[i + 1][j]);    // 下
                    sum += (j == 0 || !grid[i][j - 1]);                  // 左
                    sum += (j == grid[0].size() - 1 || !grid[i][j + 1]); // 右
                }
            }
        }
        return sum;
    }
};

// 3 operation:insert, delete, replace
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.length(), n = word2.length();
        // int dp[m + 1][n + 1]; -> 使用此宣告法會出現VLA警告(variable length array),也就是不允許變數長度陣列
        //  而標準做法是二維陣列長度必須是編譯器常數,因m跟n都是編譯時才知道值,要用vector來動態分配
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); // 初始化為0
        for (int i = 0; i < m + 1; ++i)
            dp[i][0] = i; // dp[i][0] = i -> word1的前i個字元要變空字串需要i次刪除
        for (int i = 0; i < n + 1; ++i)
            dp[0][i] = i; // dp[0][i] = i -> 空字串要變word2的前i個字元要i次插入
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (word1[i - 1] == word2[j - 1]) // 如果一樣就不用操作
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = 1 + min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
                /*+1為多一個操作
                    dp[i-1][j]: delete操作,所以往上看一個row
                    dp[i][j-1]: inser操作,所以往前看一個col
                    dp[i-1][j-1]: Replac操作,所以往左上角(跟相同一樣的道理但多1replace成本)
                 */
                /* dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
                    ->c++的min只能有兩個參數,方法可改為
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}); ->c++11以上版本提供加上大括號可以比較多個
                    dp[i][j] = 1 + min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
                */
            }
        }
        return dp[m][n];
    }
};
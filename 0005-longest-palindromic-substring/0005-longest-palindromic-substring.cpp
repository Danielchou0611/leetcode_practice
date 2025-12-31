#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    string longestPalindrome(string s) // 找出最長回文
    {
        string result = "";
        int length = s.length();
        if (length == 1)
            return s;
        vector<vector<bool>> dp(length, vector<bool>(length, false));
        int start = 0, end = 0, max_len = 1;
        for (int i = 0; i < length; i++)
        {
            dp[i][i] = true;
            for (int j = 0; j < i; j++)
            {
                if (s[j] == s[i] && (i - j <= 2 || dp[j + 1][i - 1]))   //長度如果小於3就一定是回文
                {
                    dp[j][i] = true;
                    if (i - j + 1 > max_len)
                    {
                        max_len = i - j + 1;
                        start = j;
                        end = i;
                    }
                }
            }
        }
        return s.substr(start, end - start + 1);
    }
};
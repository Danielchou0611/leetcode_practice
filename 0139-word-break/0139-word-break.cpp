// s是否能完全拆分為wordlist(可重複利用)
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        // bool dp[s.size() + 1];
        // for (int i = 0; i <= s.size(); i++)
        //     dp[i] = false;
        int n = s.size();
        vector<bool> dp(n + 1, false); // initial
        dp[0] = true;
        unordered_set<string> dictionary(wordDict.begin(), wordDict.end()); // 加速搜尋從O(n)變成O(1), 存放不重複的元素
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (dp[j] && dictionary.count(s.substr(j, i - j))) // 從j位置開始取i-j長度
                {
                    dp[i] = true;
                    break; // 找到就繼續dp, 後面的尋找無意義
                }
            }
        }
        return dp[n];
    }
};
/*
    圖解 s="leetcode", wordDist=["leet","code"]
    dp: T F F F F F F F F
    最後變成:
    dp:T F F F T F F F T
*/
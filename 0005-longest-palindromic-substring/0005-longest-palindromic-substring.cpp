#include <string>
#include <vector>
using namespace std;
/*
    Solution 1: dynamic programming skill
    Time Complexity: O(n^2)
    Space Complexity: O(n^2)
*/

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
                if (s[j] == s[i] && (i - j <= 2 || dp[j + 1][i - 1]))
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

/*
    Solution 2 : 利用中心點往左右找
    Time Complexity: O(n^2)
    Space Complexity: O(1)
 */
// class Solution
// {
// public:
//     string longestPalindrome(string s)
//     {
//         int length = s.length();
//         int start = 0, max_len = 1;
//         // 宣告一個lambda function，[&]的意思是capture by reference，意思是可以直接修改外部變數max_len跟start
//         auto expand = [&](int left, int right)
//         {
//             while (left >= 0 && right < length && s[left] == s[right])
//             {
//                 if (right - left + 1 > max_len)
//                 {
//                     max_len = right - left + 1;
//                     start = left;
//                 }
//                 left--;
//                 right++;
//             }
//         };

//         for (int i = 0; i < length; i++)
//         {
//             expand(i, i);     // odd length，exL abbd最後只有max_len=1
//             expand(i, i + 1); // even length，ex: abbd的中心在bb
//         }
//         return s.substr(start, max_len);
//     }
// };
/*
    [捕捉方式](參數) -> 回傳型別
    []：捕捉清單 (capture list)，決定 Lambda 可以存取哪些外部變數。
    常見用法：
    [&] → 捕捉所有外部變數 以引用。
    [=] → 捕捉所有外部變數 以值複製。
    [&x, y] → 捕捉 x 以引用，y 以值。
    [this] → 捕捉當前物件的 this 指標。
*/

// Solution 3: 將Solution 2改為function的模式
// class Solution
// {
// public:
//     int start;
//     int max_len;
//     string longestPalindrome(string s)
//     {
//         int length = s.length();
//         start = 0, max_len = 1;
//         // 宣告一個lambda function，[&]的意思是capture by reference，意思是可以直接修改外部變數max_len跟start

//         for (int i = 0; i < length; i++)
//         {
//             expand(s, i, i);     // odd length，exL abbd最後只有max_len=1
//             expand(s, i, i + 1); // even length，ex: abbd的中心在bb
//         }
//         return s.substr(start, max_len);
//     }
//     void expand(const string &s, int left, int right) // 用reference就不用複製字串，效率更好,const: read only
//     {
//         int length = s.length();
//         while (left >= 0 && right < length && s[left] == s[right])
//         {
//             if (right - left + 1 > max_len)
//             {
//                 max_len = right - left + 1;
//                 start = left;
//             }
//             left--;
//             right++;
//         }
//     }
// };
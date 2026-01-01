/*
    Solution 2 : 利用中心點往左右找
    Time Complexity: O(n^2)
    Space Complexity: O(n^2)
 */
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int length = s.length();
        int start = 0, max_len = 1;
        // 宣告一個lambda function，[&]的意思是capture by reference，意思是可以直接修改外部變數max_len跟start
        auto expand = [&](int left, int right)
        {
            while (left >= 0 && right < length && s[left] == s[right])
            {
                if (right - left + 1 > max_len)
                {
                    max_len = right - left + 1;
                    start = left;
                }
                left--;
                right++;
            }
        };

        for (int i = 0; i < length; i++)
        {
            expand(i, i);     // odd length，exL abbd最後只有max_len=1
            expand(i, i + 1); // even length，ex: abbd的中心在bb
        }
        return s.substr(start, max_len);
    }
};
/*
    [捕捉方式](參數) -> 回傳型別
    []：捕捉清單 (capture list)，決定 Lambda 可以存取哪些外部變數。
    常見用法：
    [&] → 捕捉所有外部變數 以引用。
    [=] → 捕捉所有外部變數 以值複製。
    [&x, y] → 捕捉 x 以引用，y 以值。
    [this] → 捕捉當前物件的 this 指標。
*/
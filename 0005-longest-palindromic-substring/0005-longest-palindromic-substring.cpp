// Solution 3: 將Solution 2改為function的模式
class Solution
{
public:
    int start;
    int max_len;
    string longestPalindrome(string s)
    {
        int length = s.length();
        start = 0, max_len = 1;
        // 宣告一個lambda function，[&]的意思是capture by reference，意思是可以直接修改外部變數max_len跟start

        for (int i = 0; i < length; i++)
        {
            expand(s, i, i);     // odd length，exL abbd最後只有max_len=1
            expand(s, i, i + 1); // even length，ex: abbd的中心在bb
        }
        return s.substr(start, max_len);
    }
    void expand(const string &s, int left, int right) // 用reference就不用複製字串，效率更好,const: read only
    {
        int length = s.length();
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
    }
};
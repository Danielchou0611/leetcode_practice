#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
    Solution:利用backtracking
    time complexity:O(n*2^n);
    space complexity: O(n)
*/

class Solution
{
private:
    void backtracking(string &s, int start, vector<string> &path, vector<vector<string>> &result)
    {
        if (start == s.length())
        {
            result.push_back(path);
            return;
        }
        for (int i = start; i < s.length(); i++)
        {
            if (isPalindrome(s.substr(start, i - start + 1)))
            {
                path.push_back(s.substr(start, i - start + 1));
                backtracking(s, i + 1, path, result);
                path.pop_back();    //判斷完這層之後就跳到下一層，並把
            }
        }
    }
    bool isPalindrome(string s) // 判斷是否為palindrome
    {
        int left = 0, right = s.length() - 1;
        while (left < right) // left==right不用檢測(string長度為奇數)
        {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

public:
    vector<vector<string>> partition(string s) // 所有的palindrome(回文)分割
    {
        vector<vector<string>> result;
        vector<string> path;
        backtracking(s, 0, path, result);
        return result;
    }
};
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

// key:用backtrack法:是一種DFS,"試一條路,不行就退回來換另一條路
class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return {}; // 回傳空陣列
        map<char, string> phone{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}}; // 建立一個對應表

        vector<string> result;                        // result存結果
        string path;                                  // path是目前已經選擇的字母路徑
        backtracking(digits, 0, phone, path, result); // index為目前正在處理的字母位置
        return result;
    }
    void backtracking(string digits, int index, map<char, string> &phone, string &path, vector<string> &result)
    {
        if (index == digits.size()) // 當index到字串最後面代表所有數字都處理完了
        {
            result.push_back(path);
            return;
        }
        string letters = phone[digits[index]]; // letter代表現在數字對應的字母表
        for (char c : letters)                 // 遍歷letter,此loop為經典的backtrack module
        {
            path.push_back(c);
            backtracking(digits, index + 1, phone, path, result); // 探索下一層
            path.pop_back();                                      // 因為上一行探索完下一層會多一個字母所以要pop出去繼續這層(backtrack的核心在這)
        }
    }
};
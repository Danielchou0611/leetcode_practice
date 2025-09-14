#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    string intToRoman(int num)
    {
        /*
            不能用unorder_map, 因為unorder_map無順序, 可能會先處理小的而不是你所初始的順序
            大到小排序, 增加900, 400, 90, 40, 9, 4, 因為有特殊的減法規則(相同符號不能重複出現三次以上)
        */
        vector<pair<int, string>>
            roman = {{1000, "M"},
                     {900, "CM"},
                     {500, "D"},
                     {400, "CD"},
                     {100, "C"},
                     {90, "XC"},
                     {50, "L"},
                     {40, "XL"},
                     {10, "X"},
                     {9, "IX"},
                     {5, "V"},
                     {4, "IV"},
                     {1, "I"}};

        string ans = "";
        for (auto [value, s] : roman) // 遍歷
        {
            while (num >= value)
            {
                num -= value;
                ans += s;
            }
        }
        return ans;
    }
};
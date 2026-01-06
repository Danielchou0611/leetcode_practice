#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    int titleToNumber(string columnTitle)
    {
        int i = 0, count = 0;
        while (i < columnTitle.length())
        {
            count = count * 26 + (columnTitle[i] - 'A' + 1);
            i++;
        }
        return count;
    }
};
#include <vector>
#include <string>
using namespace std;
class Solution
{
private:
    vector<string> tmp;

public:
    vector<string> generateParenthesis(int n)
    {
        add(n - 1, n, "(");
        return tmp;
    }
    void add(int left, int right, string t)
    {
        if (!left && !right)
            tmp.emplace_back(t);
        if (left)
            add(left - 1, right, t + '(');
        if (right && right - 1 >= left) // 右邊大括號的數量一定要大於等於左括號,不然會產生不合法的paranthese, 且要用)結尾
            add(left, right - 1, t + ')');
    }
};
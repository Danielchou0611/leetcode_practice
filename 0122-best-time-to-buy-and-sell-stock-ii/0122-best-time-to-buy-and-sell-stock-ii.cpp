#include <vector>
using namespace std;
/*
    Solution: 重複買賣的max_profit為每個遞增區間的差間加總
    time complexity: O(n)
    space complexity: O(1)
*/
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0, min_price = prices[0], max_price = prices[0]; // price>=0
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] < prices[i - 1])
            {
                profit += max_price - min_price;
                min_price = prices[i];
            }
            max_price = prices[i];
        }
        return profit + max_price - min_price;
    }
};
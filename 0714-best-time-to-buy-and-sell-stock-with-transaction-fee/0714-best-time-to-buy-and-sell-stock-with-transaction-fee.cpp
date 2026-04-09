#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee) // reference可以直接使用到使用者的陣列,並不會再複製一份
    {
        int cash = 0, hold = -prices[0]; // cash紀錄今天沒有持有(拿著cash)的最大值,hold紀錄今天有持有股票(買了股票)的最大值
        for (int i = 1; i < prices.size(); i++)
        {
            cash = max(cash, hold + prices[i] - fee); // 看前一天沒有持有的話,今天買入會不會比較好
            hold = max(hold, cash - prices[i]);       // 看前一天有持有的話,今天賣出會不會比較好
        }
        return cash;
    }
};
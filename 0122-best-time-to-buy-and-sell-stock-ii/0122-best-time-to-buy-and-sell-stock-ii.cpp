/*
    Solution 2: 只要現在的比前一個高價就加進去max_profit
    time complexity: O(n)
    space complexity: O(1)
*/
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0; // price>=0
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] > prices[i - 1])
            {
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }
};
#include <vector>
#include <string>
#include <queue>
using namespace std;
/*
    Solution: 使用priority_queue, top就會是分數最高的
    time complexity: O(nlogn) -> priority_queue
    space complexity: O(n)
*/
class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {
        int n = score.size();
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; i++)
            pq.push({score[i], i}); // pair
        int rank = 1;
        vector<string> result(n); // 分配n個空間給vector，並且初始化為空字串
        while (!pq.empty())
        {
            int val = pq.top().first;
            int index = pq.top().second;
            pq.pop();
            if (rank == 1)
                result[index] = "Gold Medal";
            else if (rank == 2)
                result[index] = "Silver Medal";
            else if (rank == 3)
                result[index] = "Bronze Medal";
            else
                result[index] = to_string(rank); // O(n)
            rank++;
        }
        return result;
    }
};
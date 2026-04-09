#include <iostream>
#include <vector>
#include <algorithm> //提供sort()
#include <queue>     //提供prioity queue
using namespace std;
// 想法是先把pair判斷nums2元素並大排到小,這樣每次再取k個的時候,有些太大的nums2元素就不會取用(ex, nums2=1,4,5,2, k=3, 5就絕對不會被用到)
class Solution
{
public:
    long long maxScore(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<pair<int, int>> v;
        v.reserve(nums1.size()); // 預先配置空間
        for (int i = 0; i < nums1.size(); i++)
            v.push_back({nums1[i], nums2[i]});
        // begin->end是從頭到尾,rbegin->rend反之
        sort(v.begin(), v.end(), [](auto &a, auto &b)
             { return a.second > b.second; }); // 利用nums2排序大到小, return a.second > b.second;意思是按照第二個元素排序(降冪)

        long long max_score = 0,
                  curr_score = 0;
        priority_queue<int, vector<int>, greater<int>> min_heap; // 定義min heap(priority queue預設是max heap)
        // priority_queue<Type, Container, Compare>,Container是用來儲存元素的容器,Compare是比較函示(greater<int>是C++標準函式物件,表示比較時用大於來排序,也就是把最小值放top)
        // 一般max heap宣告, priority_queue<int> max_heap;

        // 範圍型for迴圈,搭配結構化綁定來遍歷contaner v(pair或tuple), auto &表示對容器裡的元素參考來取,避免重複提高效率, [n1,n2]是C++結構化綁定語法,會自動將元素的第一個成員綁到n1,第二個綁到n2
        for (auto &[n1, n2] : v)
        {
            min_heap.push(n1);
            curr_score += n1;
            if ((int)min_heap.size() > k) // 如果大於k個就要把最小的pop出去
            {
                curr_score -= min_heap.top();
                min_heap.pop(); // prioriry queue的pop無回傳值
            }
            if ((int)min_heap.size() == k)
            {
                max_score = max(max_score, curr_score * n2); // 因為是判斷nums2來大到小,所以每次進來此if時的n2都會是現在取k個裡最小的
            }
        }
        return max_score;
    }
};

/*
pyhon solution

import heapq
class Solution(object):
    def maxScore(self, nums1, nums2, k):
        pair=[(nums1[i], nums2[i]) for i in range(len(nums2))]
        pair.sort(key=lambda x:x[1], reverse=True)
        max_score, curr_score=0,0
        heap=[]
        for n1, n2 in pair:
            heapq.heappush(heap, n1)
            curr_score+=n1
            if len(heap)>k:
                curr_score-=heapq.heappop(heap)
            if len(heap)==k:
                max_score=max(max_score, curr_score*n2)
        return max_score

        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type k: int
        :rtype: int
        """
*/
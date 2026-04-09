#include <iostream>
#include <vector>
using namespace std;

// 一般作法 : O(n), 因為可能會遍歷vector所有元素 class StockSpanner
class StockSpanner
{
private:
    vector<pair<int, int>> stock; // pair.first放price, stock.second放span

public:
    StockSpanner() {} // vector預設為空
    //     // stock.push_back({price, span}); // vector插入pair要用make_pair(_,_), 不過c++11後可以用列表的方式(加{})
    //     // 不過用emplace_back就不需{}, emplace_back跟puah_back都是從後面插入,但效率更高

    int next(int price)
    {

        int span = 1;
        //++cur而不是--cur是因為這是逆向itertive, ++cur代表往下一個元素移動, cur是指標,auto是自動型別推導(也就是讓編譯器自動判斷變數的型別)
        for (auto cur = stock.rbegin(); cur != stock.rend(); ++cur) // 從尾端往前遍歷,這個迴圈是用指標的方式,rbegin最後一個元素
        {
            if (price < cur->first)
                break;
            span++;
        }
        stock.emplace_back(price, span);
        return stock.back().second;
    }
};

/*
// monotonic stack:O(1)->每個元素只會最多進出一次,專門處理連續性大小比較問題,特別適合求下一個更大/小元素
class StockSpanner
{
private:
    vector<pair<int, int>> stock;

public:
    StockSpanner() {}

    int next(int price)
    {
        int span = 1;
        while (!stock.empty() && price >= stock.back().first)
        {
            span += stock.back().second;
            stock.pop_back();
        }
        stock.emplace_back(price, span);
        return span;
    }
};
*/

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
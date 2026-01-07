// implement stack using queue
#include <queue>
class MyStack
{
private:
    std::queue<int> q;

public:
    MyStack()
    {
    }

    void push(int x) // push完後，要將原本的接在後面，這樣q.pop時才會移除最後進來的(top)
    {
        q.push(x);
        for (int i = 0; i < q.size() - 1; i++)
        {
            q.push(top()); // 也可以q.push(q.front());
            q.pop();
        }
    }

    int pop() // q.pop()無回傳值，是移除最前端的value
    {
        int t = q.front();
        q.pop(); // q.pop無回傳值
        return t;
    }

    int top()
    {
        return q.front();
    }

    bool empty()
    {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
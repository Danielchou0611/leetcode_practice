#include <vector>
using namespace std;
class Solution
{
public:
    void reorderList(ListNode *head)
    {
        if (!head->next) return;
        ListNode *first = head, *second = head;
        while (second && second->next)
        {
            first = first->next;
            second = second->next->next;
        } // first剛好在中點
        ListNode *pre = nullptr, *cur = first->next;
        first->next = nullptr;

        while (cur)
        {
            ListNode *tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        } // 反轉後pre為後半段的head

        first = head, second = pre;
        while (second)
        {
            ListNode *l1 = first->next, *l2 = second->next;
            first->next = second;
            second->next = l1;
            second = l2;
            first = l1;
        }
    }
};
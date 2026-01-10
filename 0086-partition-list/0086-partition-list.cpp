
#include <iostream>
using namespace std;
/*
    宣告兩個List，分別存小於x跟大於等於x的
    time complexity: O(n)
    space complexity: O(n)
*/
class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *small = new ListNode(0);
        ListNode *big = new ListNode(0);
        ListNode *small_head = small;
        ListNode *big_head = big;
        while (head)
        {
            if (head->val < x)
            {
                small_head->next = head;
                small_head = small_head->next;
            }
            else
            {
                big_head->next = head;
                big_head = big_head->next;
            }
            head = head->next;
        }
        big_head->next = NULL;  //避免形成cycle
        small_head->next = big->next;
        return small->next;
    }
};
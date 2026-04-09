class Solution
{
public:
    ListNode *deleteMiddle(ListNode *head)
    {
        int sum = num(head);
        if (head == NULL || sum == 1)
            return NULL;
        sum = sum / 2 - 1;
        ListNode *node = head;
        while (sum != 0)
        {
            sum--;
            node = node->next;
        }
        node->next = node->next->next;
        return head;
    }
    int num(ListNode *node)
    {
        int count = 0;
        while (node != NULL)
        {
            node = node->next;
            count++;
        }
        return count;
    }
};
class Solution(object):
    def reverseList(self, head):
        pre=None
        cur=head
        while(cur):
            head=head.next
            cur.next=pre
            pre=cur
            cur=head
        return pre
    
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
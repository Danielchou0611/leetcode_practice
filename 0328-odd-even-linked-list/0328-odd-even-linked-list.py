
class Solution(object):
    def oddEvenList(self, head):
        if not head or not head.next:
            return head
        even=head.next
        odd=head
        even_head=even
        while even and even.next:
            odd.next=even.next
            odd=odd.next
            even.next=odd.next      #也可以且even.next=even.next.next
            even=even.next
        odd.next=even_head
        return head
    
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
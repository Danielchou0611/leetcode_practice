class Solution(object):
    def pairSum(self, head):
        odd=head
        even=head
        while even and even.next:   #基數個even 或是偶數個even
            odd=odd.next
            even=even.next.next
        odd=self.reverseList(odd)
        max_value=0
        even=head
        while odd:
            max_value=max(odd.val+even.val, max_value)
            odd=odd.next
            even=even.next
        return max_value


    def reverseList(self, head):
        pre=None
        cur=head
        while cur:
            head=head.next
            cur.next=pre
            pre=cur
            cur=head
        return pre

        """
        :type head: Optional[ListNode]
        :rtype: int
        """
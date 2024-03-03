
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode *slow;
        ListNode *fast;
        ListNode *dummy_pointer=head;
        dummy_pointer=head;
        slow=fast=dummy_pointer;
        for(int i=0;i<n;i++)
        {
            fast=fast->next;
        }
        if(fast==NULL)
        {
            return head->next;
        }
        while(fast->next!=NULL)
        {
            fast=fast->next;
            slow=slow->next;
        }
        slow->next=slow->next!=NULL?slow->next->next:NULL;
        return dummy_pointer;
    }
};
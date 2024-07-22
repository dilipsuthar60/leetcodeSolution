
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) 
    {
        ListNode*temp1;
        ListNode*temp2;
        temp1=list1;
        temp2=list1;
        a--;
        while(a--)
        {
            temp1=temp1->next;
        }
        while(b--)
        {
            temp2=temp2->next;
        }
        temp1->next=list2;
        while(list2->next!=NULL)
        {
            list2=list2->next;
        }
        list2->next=temp2->next;
        return list1;
    }
};
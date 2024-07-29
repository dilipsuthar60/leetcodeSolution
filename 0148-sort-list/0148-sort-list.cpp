/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode*merge(ListNode*l1,ListNode*l2)
    {
        if(l1==NULL||l2==NULL)
        {
            return l1==NULL?l2:l1;
        }
        ListNode*dummy_node=new ListNode(-1);
        ListNode*start=dummy_node;
        while(l1!=NULL&&l2!=NULL)
        {
            if(l1->val<l2->val)
            {
                dummy_node->next=l1;
                l1=l1->next;
            }
            else
            {
                dummy_node->next=l2;
                l2=l2->next;
            }
            dummy_node=dummy_node->next;
        }
        dummy_node->next=(l1==NULL)?l2:l1;
        return start->next;
    }
    ListNode* sortList(ListNode* head) 
    {
        if(head==NULL||head->next==NULL)
        {
            return head;
        }
        ListNode*temp=NULL;
        ListNode*fast=head;
        ListNode*slow=head;
        while(fast!=NULL&&fast->next!=NULL)
        {
            fast=fast->next->next;
            temp=slow;
            slow=slow->next;
        }
        temp->next=NULL;
        ListNode*first=head;
        return merge(sortList(first),sortList(slow));
    }
};
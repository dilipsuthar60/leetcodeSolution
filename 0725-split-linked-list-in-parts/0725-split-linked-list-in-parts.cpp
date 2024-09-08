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
    int find(ListNode*node)
    {
        int count=0;
        for(count=0;node!=nullptr;count++,node=node->next);
        return count;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) 
    {
        int len=find(head);
        vector<ListNode*>v;
        int comp=len/k;
        int extra=len%k;
        for(int i=0;i<k&&head!=NULL;i++)
        {
            v.push_back(head);
            int now=comp;
            if(extra)
            {
                extra--;
                now++;
            }
            ListNode*root=NULL;
            while(now--)
            {
                root=head;
                head=head->next;
            }
            if(root!=NULL)
            {
                root->next=NULL;
            }
            
        }
        while(v.size()!=k)
        {
            v.push_back(NULL);
        }
        return v;
    }
};
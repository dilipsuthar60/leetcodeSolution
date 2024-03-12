class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) 
    {
        unordered_map<int,ListNode*>mp;
        int prefixSum=0;
        ListNode*dummy=new ListNode(0);
        dummy->next=head;
        ListNode*dummyHead=dummy;
        while(dummy!=NULL)
        {
            prefixSum+=dummy->val;
            if(mp.find(prefixSum)!=mp.end())
            {
                ListNode* prev=mp[prefixSum];
                ListNode* toRemove=prev->next;
                int p = prefixSum + ((toRemove==NULL)?0:toRemove->val);
                while(p!=prefixSum)
                {
                    mp.erase(p);
                    toRemove=toRemove->next;
                    p+=(toRemove==NULL)?0:toRemove->val;
                }
                prev->next=dummy->next;
            }
            else
            {
                mp[prefixSum]=dummy;
            }
            dummy=dummy->next;
        }
        return dummyHead->next;
    }
};
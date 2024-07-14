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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>s;
        for(auto it:nums) s.insert(it);
        ListNode*dummynode=new ListNode(-1);
        ListNode*startDummy=dummynode;
        while(head!=NULL){
            if(s.find(head->val)==s.end()){
                startDummy->next=head;
                head=head->next;
                startDummy=startDummy->next;
            }
            else{
                head=head->next;
            }
        }
        startDummy->next=NULL;
        return dummynode->next;
    }
};
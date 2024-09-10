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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode*current=head;
        while(current!=NULL&&current->next){
            int first=current->val;
            int second=current->next->val;
            ListNode* mid=new ListNode(__gcd(first,second));
            ListNode*backup=current->next;
            current->next=mid;
            mid->next=backup;
            current=backup;
        }
        return head;
    }
};
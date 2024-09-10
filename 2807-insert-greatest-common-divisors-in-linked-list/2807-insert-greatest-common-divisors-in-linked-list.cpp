class Solution {
public:
    int getGcd(int a,int b){
        if(b==0) return a;
        return getGcd(b,a%b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode*current=head;
        while(current!=NULL&&current->next){
            int first=current->val;
            int second=current->next->val;
            ListNode* mid=new ListNode(getGcd(first,second));
            ListNode*backup=current->next;
            current->next=mid;
            mid->next=backup;
            current=backup;
        }
        return head;
    }
};
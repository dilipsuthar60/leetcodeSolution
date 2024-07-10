class Solution {
public:
    struct node
    {
        node*child[2]={NULL};
        int val=0;
    };
    node*root=new node();
    void insert(int n)
    {
        node*curr=root;
        for(int i=30;i>=0;i--)
        {
            int bit=((1<<i)&n)>0?1:0;
            if(curr->child[bit]==NULL)
            {
                curr->child[bit]=new node();
            }
            curr=curr->child[bit];
        }
        curr->val=n;
    }
    int find(int n)
    {
        node*curr=root;
        for(int i=30;i>=0;i--)
        {
            int bit=((1<<i)&n)>0?1:0;
            if(curr->child[!bit]!=NULL)
            {
                curr=curr->child[!bit];
            }
            else
            {
                curr=curr->child[bit];
            }
        }
        return curr->val;
    }
    int findMaximumXOR(vector<int>& nums) 
    {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            insert(nums[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int x=find(nums[i]);
            ans=max(ans,x^nums[i]);
        }
        return ans;
    }
};
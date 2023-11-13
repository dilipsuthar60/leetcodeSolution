class Solution {
public:
    struct node{
        node*child[2]={NULL};
        int count=0;
    };
    node*root=new node();
    void insert(int num,int val)
    {
        node*curr=root;
        for(int i=20;i>=0;i--)
        {
            int bit=(num&(1<<i))>0?1:0;
            if(curr->child[bit]==NULL)
            {
                curr->child[bit]=new node();
            }
            curr=curr->child[bit];
            curr->count+=val;
        }
    }
    int find(int num)
    {
        node*curr=root;
        int ans=0;
        for(int i=20;i>=0;i--)
        {
            int bit=(num&(1<<i))>0?1:0;
            if(curr->child[!bit]&&curr->child[!bit]->count>0)
            {
                ans+=(1<<i);
                curr=curr->child[!bit];
            }
            else
            {
                curr=curr->child[bit];
            }
        }
        return ans;
    }
    int maximumStrongPairXor(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0,j=0;i<n;i++)
        {
            insert(nums[i],1);
            while(nums[i]-nums[j]>nums[j])
            {
                insert(nums[j],-1);
                j++;
            }
            ans=max(ans,find(nums[i]));
        }
        return ans;
    }
};
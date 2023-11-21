class Solution {
public:
    int tree[50000*3];
    void build(int index,vector<int>&nums,int l,int r)
    {
        if(l==r)
        {
            tree[index]=nums[l];
            return ;
        }
        int m=(l+r)/2;
        build(index*2+1,nums,l,m);
        build(index*2+2,nums,m+1,r);
        tree[index]=max(tree[2*index+1],tree[2*index+2]);
    }
    int get(int index,int l,int r,int L,int R)
    {
        if(r<L||l>R)
        {
            return 0;
        }
        if(L<=l&&r<=R)
        {
            return tree[index];
        }
        int m=(l+r)/2;
        return max(get(2*index+1,l,m,L,R),get(2*index+2,m+1,r,L,R));
    }
    vector<int> leftmostBuildingQueries(vector<int>&nums, vector<vector<int>>& q) 
    {
        int n=nums.size();
        memset(tree,0,sizeof(tree));
        build(0,nums,0,n-1);
        vector<int>ans(q.size(),-1);
        for(int i=0;i<q.size();i++)
        {
            int l=q[i][0];
            int r=q[i][1];
            if(l>r)
            {
                swap(l,r);
            }
            if(l==r)
            {
                ans[i]=l;
                continue;
            }
            if(nums[l]<nums[r])
            {
                ans[i]=r;
                continue;
            }
            int left=r+1;
            int right=n-1;
            while(left<=right)
            {
                int m=(left+right)/2;
                int value=get(0,0,n-1,r,m);
                if(value>nums[l]&&value>nums[r])
                {
                    ans[i]=m;
                    right=m-1;
                }
                else
                {
                    left=m+1;
                }
            }
        }
        return ans;
    }
};
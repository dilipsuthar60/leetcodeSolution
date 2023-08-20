class Solution {
public:
    int dp[400001];
    int bs(vector<vector<int>>&nums,int index)
    {
        int l=0;
        int r=nums.size()-1;
        int ans=nums.size();
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(nums[index][1]<nums[mid][0])
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
    int find(vector<vector<int>>&nums,int index)
    {
        if(index>=nums.size())
        {
            return 0;
        }
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        int notTake=find(nums,index+1);
        int findIndex=bs(nums,index);
        int take=nums[index][2]+find(nums,findIndex);
        return dp[index]= max(notTake,take);
    }
    int maximizeTheProfit(int n, vector<vector<int>>&nums) 
    {
        memset(dp,-1,sizeof(dp));
        sort(nums.begin(),nums.end());
        return find(nums,0);
    }
};
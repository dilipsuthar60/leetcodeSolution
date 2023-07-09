class Solution {
public:
    int dp[1101];
    int find(vector<int>&nums,int index,int target)
    {
        if(index==nums.size()-1)
        {
            return 0;
        }
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        int ans=-1e9;
        for(int i=index+1;i<nums.size();i++)
        {
            if(abs(nums[index]-nums[i])<=target)
            {
                ans=max(ans,1+find(nums,i,target));
            }
        }
        return dp[index]= ans;
    }
    int maximumJumps(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        int value=find(nums,0,target);
        if(value<0)
        {
            return -1;
        }
        return value;
    }
};
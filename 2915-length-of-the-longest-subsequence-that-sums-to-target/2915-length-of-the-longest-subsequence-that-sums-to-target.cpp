class Solution {
public:
    int n;
    int dp[1001][1001];
    int find(vector<int>&nums,int index,int target)
    {
        if(target==0)
        {
            return 0;
        }
        if(index>=n||target<0)
        {
            return -1e9;
        }
        if(dp[index][target]!=-1)
        {
            return dp[index][target];
        }
        int take=1+find(nums,index+1,target-nums[index]);
        int notTake=find(nums,index+1,target);
        return dp[index][target]= max(take,notTake);
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        n=nums.size();
        memset(dp,-1,sizeof(dp));
        int val=find(nums,0,target);
        return val<0?-1:val;
    }
};
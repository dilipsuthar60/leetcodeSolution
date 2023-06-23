class Solution {
public:
    int minTaps(int n, vector<int>&nums) {
        vector<int>dp(n+1,INT_MAX/2);
        dp[0]=0;
        for(int i=0;i<nums.size();i++)
        {
            int l=max(i-nums[i],0);
            int r=min(n,i+nums[i]);
            for(int j=l+1;j<=r;j++)
            {
                dp[j]=min(dp[j],dp[l]+1);
            }
        }
        return dp[n]==INT_MAX/2?-1:dp[n];
    }
};
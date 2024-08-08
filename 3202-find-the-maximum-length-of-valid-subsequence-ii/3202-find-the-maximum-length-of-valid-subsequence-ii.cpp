class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int ans=0;
        int n=nums.size();
        vector<vector<int>>dp(nums.size()+1,vector<int>(k,1));
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int rem=(nums[i]+nums[j])%k;
                dp[i][rem]=max(dp[i][rem],1+dp[j][rem]);
                ans=max(ans,dp[i][rem]);
            }
        }
        return ans;
    }
};
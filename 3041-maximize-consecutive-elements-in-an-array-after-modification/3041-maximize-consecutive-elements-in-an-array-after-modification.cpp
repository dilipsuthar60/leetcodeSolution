class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        unordered_map<int,int>dp;
        int ans=0;
        for(int i=n-1;i>=0;i--)
        {
            dp[nums[i]]=max(dp[nums[i]+1]+1,dp[nums[i]]);
            dp[nums[i]+1]=max(dp[nums[i]+2]+1,dp[nums[i]+1]);
            ans=max({ans,dp[nums[i]],dp[nums[i]+1]});
        }
        return ans;
    }
};
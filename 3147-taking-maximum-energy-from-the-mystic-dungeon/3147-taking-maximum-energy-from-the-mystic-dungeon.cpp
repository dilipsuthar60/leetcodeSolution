class Solution {
public:
    int maximumEnergy(vector<int>&nums, int k) {
        int n=nums.size();
        vector<int>dp(n+1,-1e6);
        for(int i=n-1;i>=0;i--)
        {
            if(i+k<n){
             dp[i]=nums[i]+dp[i+k];
            }
            else{
                dp[i]=nums[i];
            }
        }
        return *max_element(dp.begin(),dp.end());       
    }
};
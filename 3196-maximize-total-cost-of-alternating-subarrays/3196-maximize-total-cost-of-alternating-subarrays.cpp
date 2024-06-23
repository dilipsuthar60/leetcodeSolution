class Solution {
public:
    long long dp[100005][2];
    long long find(vector<int>&nums,int index,int take){
        if(index>=nums.size()) return 0;
        if(dp[index][take]!=-1) return dp[index][take];
        long long ans=nums[index]+find(nums,index+1,1);
        if(take){
            ans=max(ans,-nums[index]+find(nums,index+1,0));
        }
        return dp[index][take]= ans;
    }
    long long maximumTotalCost(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return find(nums,0,0);
    }
};
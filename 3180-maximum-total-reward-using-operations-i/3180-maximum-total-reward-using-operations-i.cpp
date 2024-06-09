class Solution {
public:
    int dp[2001][4001];
    int find(vector<int>&nums,int index,int sum=0){
        if(index>=nums.size()) return 0;
        if(dp[index][sum]!=-1) return dp[index][sum];
        int result=find(nums,index+1,sum);
        if(sum<nums[index]){
            result=max(result,nums[index]+find(nums,index+1,sum+nums[index]));
        }
        return dp[index][sum] = result;
    }
    int maxTotalReward(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        sort(nums.begin(),nums.end());
        return find(nums,0);
    }
};
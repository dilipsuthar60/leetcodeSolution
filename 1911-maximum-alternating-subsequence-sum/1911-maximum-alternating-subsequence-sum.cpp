class Solution {
public:
    vector<vector<long long>>dp;
    long long find(vector<int>&nums,int index,int f=1){
        if(index>=nums.size()) return 0;
        if(dp[index][f]!=1e12) return dp[index][f];
        long long notTake=find(nums,index+1,f);
        long long take=(f?nums[index]:-nums[index])+find(nums,index+1,f^1);
        return dp[index][f] = max(take,notTake);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        dp=vector<vector<long long>>(nums.size()+1,vector<long long>(2,1e12));
        return find(nums,0);
    }
};
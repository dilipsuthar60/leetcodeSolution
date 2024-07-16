class Solution {
public:
    const int mod=1e9+7;
    long long dp[1005][1005];
    long long find(vector<int>&nums,int k,int index,int sum=0){
        if(index>=nums.size()) return sum<k;
        if(sum>k) return 0;
        if(dp[index][sum]!=-1) return dp[index][sum]%mod;
        long long take=find(nums,k,index+1,sum+nums[index]);
        long long notTake=find(nums,k,index+1,sum);
        return dp[index][sum] = (take+notTake)%mod;
    }
    int countPartitions(vector<int>& nums, int k) {
        memset(dp,-1,sizeof(dp));
        long long totalSum=accumulate(nums.begin(),nums.end(),0ll);
        if(totalSum<2*k) return 0;
        long long countLess=find(nums,k,0);
        long long totalSubset=1;
        for(int i=1;i<=nums.size();i++){
            totalSubset*=2;
            totalSubset%=mod;
        }
        long long result=(totalSubset-2*countLess+mod)%mod;
        return result;
    }
};
class Solution {
public:
    const int mod=1e9+7;
    long long dp[201][201][201];
    long long find(vector<int>&nums,int index,int g1,int g2){
        if(index>=nums.size()){
            return g1&&g2&&(g1==g2);
        }
        if(dp[index][g1][g2]!=-1) return dp[index][g1][g2]%mod;
        long long ans=find(nums,index+1,g1,g2);
        ans+=find(nums,index+1,__gcd(g1,nums[index]),g2);
        ans+=find(nums,index+1,g1,__gcd(g2,nums[index]));
        return dp[index][g1][g2]= ans%mod;
    }
    int subsequencePairCount(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return find(nums,0,0,0)%mod;
    }
};
class Solution {
public:
    const int mod=1e9+7;
    long long dp[2001][51];
    int find(vector<int>&nums,int index,int prev){
        if(index>=nums.size()) return 1;
        if(dp[index][prev]!=-1) return dp[index][prev]%mod;
        long long ans=0;
        for(int i=prev;i<=nums[index];i++){
            int k=nums[index]-i;
            if((index==0)||(k<=nums[index-1]-prev)){
                ans+=find(nums,index+1,i);
            }
        }
        return dp[index][prev]= ans%mod;
    }
    int countOfPairs(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return find(nums,0,0);
    }
};
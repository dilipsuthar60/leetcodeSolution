class Solution {
public:
    int n;
    int mod=1e9+7;
    long long dp[16][1<<15];
    long long find(vector<int>&nums,int prev,int mask)
    {
        if(mask==((1<<n)-1))
        {
            return 1;
        }
        if(dp[prev+1][mask]!=-1)
        {
            return dp[prev+1][mask]%mod;
        }
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            if((mask&(1<<i))==0&&(prev==-1||(nums[prev]%nums[i]==0||nums[i]%nums[prev]==0)))
            {
                ans+=find(nums,i,mask|(1<<i));
            }
        }
        return dp[prev+1][mask]=ans%mod;
    }
    int specialPerm(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        n=nums.size();
        return find(nums,-1,0)%mod;
    }
};
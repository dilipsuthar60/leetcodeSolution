class Solution {
public:
    long long dp[400][400];
    int mod=1e9+7;
    int find(int n,int x,int index)
    {
        if(n<0)
        {
            return 0;
        }
        if(n==0)
        {
            return 1;
        }
        if(pow(index,x)>n)
        {
            return 0;
        }
        if(dp[n][index]!=-1)
        {
            return dp[n][index]%mod;
        }
        int value=pow(index,x);
        long long take=find(n-value,x,index+1);
        long long nottake=find(n,x,index+1);
        return dp[n][index]= (take+nottake)%mod;
    }
    int numberOfWays(int n, int x) {
        memset(dp,-1,sizeof(dp));
        return find(n,x,1)%mod;
    }
};
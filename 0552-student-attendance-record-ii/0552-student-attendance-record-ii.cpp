class Solution {
public:
    const int mod=1e9+7;
    long long dp[100005][3][3];
    int find(int i,int A,int L,int n)
    {
        if(i==n)
        {
            return 1;
        }
        if(dp[i][A][L]!=-1)
        {
            return dp[i][A][L];
        }
        int res=0;
        res=find(i+1,A,0,n);
        if(A<1)
        {
            res=(res+find(i+1,A+1,0,n))%mod;
        }
        if(L<2)
        {
            res=(res+find(i+1,A,L+1,n))%mod;
        }
        return dp[i][A][L]=res%mod;
    }
    int checkRecord(int n) {
        memset(dp,-1,sizeof(dp));
        return find(0,0,0,n);
    }
};
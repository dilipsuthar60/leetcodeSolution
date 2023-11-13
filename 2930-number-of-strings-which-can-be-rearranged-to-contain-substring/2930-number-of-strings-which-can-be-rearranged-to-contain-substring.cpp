class Solution {
public:
    int mod=1e9+7;
    long long dp[100005][2][2][2][2];
    long long find(int n,int index,int a,int b,int c,int d)
    {
        if(index==n)
        {
            return a==1&&b==1&&c==1&&d==1;
        }
        if(dp[index][a][b][c][d]!=-1)
        {
            return dp[index][a][b][c][d]%mod;
        }
        long long ans=0;
        for(char ch='a';ch<='z';ch++)
        {
            if(ch=='l'&&a==0)
            {
                ans+=find(n,index+1,1,b,c,d);
            }
            else if(ch=='e'&&b==0)
            {
                ans+=find(n,index+1,a,1,c,d);
            }
            else if(ch=='e'&&c==0)
            {
                ans+=find(n,index+1,a,b,1,d);
            }
            else if(ch=='t'&&d==0)
            {
                ans+=find(n,index+1,a,b,c,1);
            }
            else
            {
                ans+=find(n,index+1,a,b,c,d);
            }
        }
        return dp[index][a][b][c][d] = ans%mod;
    }
    int stringCount(int n) {
        memset(dp,-1,sizeof(dp));
        return find(n,0,0,0,0,0)%mod;
    }
};
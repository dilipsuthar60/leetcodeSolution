class Solution {
public:
    const int mod = 1e9+7;
    long long dp[1001][1001][2];
    long long find(int n,int index,int k,int start){
        if(k==0) return 1;
        if(index==n) return 0;
        if(dp[index][k][start]!=-1) return dp[index][k][start]%mod;
        long long ans=find(n,index+1,k,start);
        if(start){
            ans+=find(n,index+1,k,0);
        }
        else{
            ans+=find(n,index,k-1,1);
        }
        return dp[index][k][start]= ans%mod;
    }
    int numberOfSets(int n, int k) {
        memset(dp,-1,sizeof(dp));
        return find(n,0,k,1)%mod;
    }
};
class Solution {
public:
    long long dp[4][100005];
    long long find(vector<int>&a,vector<int>&b,int i,int j){
        if(i>=a.size()) return 0;
        if(j>=b.size()) return -1e18;
        if(dp[i][j]!=-1) return dp[i][j];
        long long take= 1ll*a[i]*b[j]+find(a,b,i+1,j+1);   
        long long notTake = find(a,b,i,j+1);
        return dp[i][j] = max(take,notTake);
    }
    long long maxScore(vector<int>& a, vector<int>& b) {
        memset(dp,-1,sizeof(dp));
        return find(a,b,0,0);
    }
};
class Solution {
public:
    long long dp[301][301][100];
    const int mod=1e9+7;
    long long find(vector<vector<int>>&mat,int i,int j,int sum,int k){
        if(i>=mat.size()||j>=mat[0].size()){
            return 0;
        }
        if(i==mat.size()-1&&j==mat[0].size()-1){
            return (sum^mat[i][j])==k;
        }
        if(dp[i][j][sum]!=-1){
            return dp[i][j][sum]%mod;
        }
        long long a=find(mat,i+1,j,sum^mat[i][j],k);
        long long b=find(mat,i,j+1,sum^mat[i][j],k);
        return dp[i][j][sum] = (a+b)%mod;
    }
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        memset(dp,-1, sizeof(dp));
        return find(grid,0,0,0,k);
    }
};
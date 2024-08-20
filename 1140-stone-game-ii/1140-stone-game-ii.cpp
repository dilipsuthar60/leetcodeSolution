class Solution {
public:
    int dp[101][301][2];
    int solve(int i , int n , int m , vector<int>& v, int a){
        if(i>=n){
            return 0;
        }
        if(dp[i][m][a]!=-1) return dp[i][m][a];
        int ans = (a==1)?0:1e9;
        int curr=0;
        for(int j = i;j<n&&j<i+2*m;j++){
            curr+=v[j];
            if(a==1){
                ans = max(ans,curr+solve(j+1,n,max(m,j-i+1),v, 1-a));
            }
            else{
                ans = min(ans,0+solve(j+1,n,max(m,j-i+1),v, 1-a));
            }
        }
        
        return dp[i][m][a]=ans;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,n,1,piles,1);
    }

};
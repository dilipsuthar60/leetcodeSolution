class Solution {
public:
    int countSquares(vector<vector<int>>& mat)
    {
        int count=0;
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(mat[i-1][j-1]==1)
                {
                    dp[i][j]=min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]})+1;
                }
                count+=dp[i][j];
            }
        }
        return count;
    }
};
class Solution {
public:
    int countSubmatrices(vector<vector<int>>&mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        int count=0;
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0)
                {
                    dp[i][j]=(j)?dp[i][j-1]+mat[i][j]:mat[i][j];
                }
                else if(j==0)
                {
                    dp[i][j]=(i)?dp[i-1][j]+mat[i][j]:mat[i][j];
                }
                else
                {
                    dp[i][j]=mat[i][j]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
                }
                if(dp[i][j]<=k)
                {
                    count++;
                }
            }
        }
        return count;
    }
};
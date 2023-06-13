class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) 
    {
        int n=mat.size();
        int m=mat[0].size();
        map<int,vector<pair<int,int>>>nums;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                nums[mat[i][j]].push_back({i,j});
            }
        }
        int ans=0;
        vector<int>row(n,0);
        vector<int>col(m,0);
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(auto &[value,v]:nums)
        {
            for(auto &[x,y]:v)
            {
                dp[x][y]=max(row[x],col[y])+1;
                ans=max(ans,dp[x][y]);
            }
            for(auto &[x,y]:v)
            {
                row[x]=max(row[x],dp[x][y]);
                col[y]=max(col[y],dp[x][y]);
            }
        }
        return ans;
    }
};
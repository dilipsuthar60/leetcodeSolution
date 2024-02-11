class Solution {
public:
    int n;
    int m;
    int dp[71][71][71];
    int find(vector<vector<int>>&mat,int r,int c1,int c2)
    {
        if(r==n)
        {
            return 0;
        }
        if(dp[r][c1][c2]!=-1)
        {
            return dp[r][c1][c2];
        }
        int ans=0;
        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
                int nc1=c1+i;
                int nc2=c2+j;
                if(nc1>=0&&nc1<m&&nc2>=0&&nc2<m)
                {
                    ans=max(ans,find(mat,r+1,nc1,nc2));
                }
            }
        }
        int ch=(c1==c2)?mat[r][c1]:mat[r][c1]+mat[r][c2];
        return dp[r][c1][c2]=ans+ch;
    }
    int cherryPickup(vector<vector<int>>& grid) 
    {
        memset(dp,-1,sizeof(dp));
        n=grid.size();
        m=grid[0].size();
        return find(grid,0,0,m-1);
    }
};
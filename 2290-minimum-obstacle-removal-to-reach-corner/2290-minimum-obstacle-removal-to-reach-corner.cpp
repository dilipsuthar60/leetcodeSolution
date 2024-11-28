class Solution {
public:
    int minimumObstacles(vector<vector<int>>& mat) {
         vector<pair<int,int>>d={{-1,0},{0,1},{1,0},{0,-1}};
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<int,int>>q;
        q.push({0,0});
        int dp[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                dp[i][j]=1e9;
            }
        }
        dp[0][0]=0;
        while(q.size())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                auto temp=q.front();
                q.pop();
                int x=temp.first;
                int y=temp.second;
                for(auto it:d)
                {
                    int nx=x+it.first;
                    int ny=y+it.second;
                    if(nx>=0&&ny>=0&&nx<n&&ny<m&&dp[x][y]+mat[nx][ny]<dp[nx][ny])
                    {
                        dp[nx][ny]=dp[x][y]+mat[nx][ny];
                         q.push({nx,ny});
                    }
                }
            }
        }
        return dp[n-1][m-1];
                
    }
};
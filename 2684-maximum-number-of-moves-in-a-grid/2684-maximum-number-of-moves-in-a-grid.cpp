class Solution {
public:
    int maxMoves(vector<vector<int>>& mat) 
    {
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            q.push({i,0});
        }
        int level=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<pair<int,int>>d={{-1,1},{0,1},{1,1}};
        while(q.size())
        {
            int size=q.size();
            while(size--)
            {
                auto [x,y]=q.front();
                q.pop();
                if(vis[x][y])
                {
                    continue;
                }
                vis[x][y]=1;
                for(auto it:d)
                {
                    int nx=x+it.first;
                    int ny=y+it.second;
                    if(nx>=0&&ny>=0&&nx<n&&ny<m&&mat[x][y]<mat[nx][ny])
                    {
                        q.push({nx,ny});
                    }
                }
            }
            level++;
        }
        return level-1;
    }
};
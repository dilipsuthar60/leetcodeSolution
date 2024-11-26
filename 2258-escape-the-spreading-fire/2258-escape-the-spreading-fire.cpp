class Solution {
public:
    int n,m;
    vector<pair<int,int>>d={{-1,0},{0,1},{1,0},{0,-1}};
    void find(vector<vector<int>>&mat,vector<vector<int>>&dis)
    {
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==1)
                {
                    q.push(i*m+j);
                    dis[i][j]=0;
                }
                if(mat[i][j]==2)
                {
                    dis[i][j]=-1;
                }
            }
        }
        int level=1;
        while(q.size())
        {
            int size=q.size();
            while(size--)
            {
                auto temp=q.front();
                q.pop();
                int x=temp/m;
                int y=temp%m;
                for(auto it:d)
                {
                    int nx=x+it.first;
                    int ny=y+it.second;
                    if(nx>=0&&ny>=0&&nx<n&&ny<m&&dis[nx][ny]==INT_MAX&&mat[nx][ny]==0)
                    {
                        dis[nx][ny]=level;
                        q.push(nx*m+ny);
                    }
                }
            }
            level++;
        }
    }
    bool check(vector<vector<int>>&dis,int mid)
    {
        queue<pair<int,int>>q;
        q.push({0,mid});
        int vis[n][m];
        memset(vis,0,sizeof(vis));
        while(q.size())
        {
            auto [temp,cost]=q.front();
            q.pop();
            int x=temp/m;
            int y=temp%m;
            vis[x][y]=1;
            if(x==n-1&&y==m-1)
            {
                return true;
            }
            for(auto it:d)
            {
                int nx=x+it.first;
                int ny=y+it.second;
                if(nx>=0&&ny>=0&&nx<n&&ny<m&&dis[nx][ny]!=-1&&!vis[nx][ny]&&(cost+1<dis[nx][ny]||(nx==n-1&&ny==m-1&&cost+1<=dis[nx][ny])))
                {
                    q.push({nx*m+ny,cost+1});
                }
            }
        }
        return false;
    }
    int maximumMinutes(vector<vector<int>>&mat) 
    {
         n=mat.size();
         m=mat[0].size();
        vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
        find(mat,dis);
        int l=0;
        int r=1e9;
        int ans=-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(check(dis,mid))
            {
                l=mid+1;
                ans=mid;
            }
            else
            {
                r=mid-1;
            }
        }
        return ans;
    }
};
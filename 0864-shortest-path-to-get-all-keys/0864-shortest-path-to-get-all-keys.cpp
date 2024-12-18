class Solution {
public:
    vector<pair<int,int>>dir={{-1,0},{1,0},{0,-1},{0,1}};
    int shortestPathAllKeys(vector<string>&mat) 
    {
        int n=mat.size();
        int m=mat[0].size();
        int k=0;
        int startx,starty;
        startx=starty=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]=='@')
                {
                    startx=i;
                    starty=j;
                }
                if(mat[i][j]>='A'&&mat[i][j]<='F')
                {
                    k++;
                }
            }
        }
        queue<pair<int,int>>q;
        q.push({startx*m+starty,0});
        int vis[n+1][m+1][65];
        memset(vis,0,sizeof(vis));
        vis[startx][starty][0]=1;
        int level=0;
        while(q.size())
        {
            int size=q.size();
            for(int j=0;j<size;j++)
            {
                auto temp=q.front();
                q.pop();
                int x=temp.first/m;
                int y=temp.first%m;
                int mask=temp.second;
                if(mask==((1<<k)-1))
                {
                    return level;
                }
                for(auto &it:dir)
                {
                    int nx=x+it.first;
                    int ny=y+it.second;
                    int now_mask=mask;
                    if(nx>=0&&ny>=0&&nx<n&&ny<m&&mat[nx][ny]!='#')
                    {
                        if(isupper(mat[nx][ny]))
                        {
                            if(!(mask&(1<<(mat[nx][ny]-'A'))))
                            {
                                continue;
                            }
                        }
                        if(islower(mat[nx][ny]))
                        {
                            now_mask=(mask|(1<<(mat[nx][ny]-'a')));
                        }
                        if(!vis[nx][ny][now_mask])
                        {
                            q.push({nx*m+ny,now_mask});
                            vis[nx][ny][now_mask]=1;
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
};
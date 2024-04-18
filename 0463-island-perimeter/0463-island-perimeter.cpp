class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<pair<int,int>>d={{-1,0},{1,0},{0,-1},{0,1}};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    count+=4;
                    for(auto it:d)
                    {
                        int nx=i+it.first;
                        int ny=j+it.second;
                        if(nx>=0&&ny>=0&&nx<n&&ny<m&&grid[nx][ny]==1)
                        {
                            count--;
                        }
                    }
                }
            }
        }
        return count;
    }
};
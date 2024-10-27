class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=-1e8;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int prevMin=1e9;
                if(i==0&&j==0) continue;
                if(i>0) prevMin=min(prevMin,grid[i-1][j]);
                if(j>0) prevMin=min(prevMin,grid[i][j-1]);
                ans=max(ans,grid[i][j]-prevMin);
                grid[i][j]=min(grid[i][j],prevMin);
            }
        }
        return ans;
    }
};
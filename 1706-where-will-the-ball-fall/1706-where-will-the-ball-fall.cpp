class Solution {
public:
    int n,m;
    int find(vector<vector<int>>&mat,int i,int j){
        if(i==n) return j;
        if(mat[i][j]==1&&(j+1<m&&mat[i][j+1]==1)){
            return find(mat,i+1,j+1);
        }
        if(mat[i][j]==-1&&(j-1>=0&&mat[i][j-1]==-1)){
            return find(mat,i+1,j-1);
        }
        return -1;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<int>ans(m,-1);
        for(int i=0;i<m;i++){
            ans[i]=find(grid,0,i);
        }
        return ans;
    }
};
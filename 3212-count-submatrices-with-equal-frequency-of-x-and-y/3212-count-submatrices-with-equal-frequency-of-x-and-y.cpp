class Solution {
public:
    int n,m;
    vector<vector<int>>matrixPrefix(vector<vector<char>>&mat,char value){
        vector<vector<int>>prefix(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                prefix[i][j]=prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1]+(mat[i-1][j-1]==value) ;
            }
        }
        return prefix;
    }
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>>prefixX=matrixPrefix(grid,'X');
        vector<vector<int>>prefixY=matrixPrefix(grid,'Y');
        int countSubMatrix=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(prefixX[i][j]==prefixY[i][j]&&prefixX[i][j]>0){
                    countSubMatrix++;
                }
            }
        }
        return countSubMatrix;
    }
};
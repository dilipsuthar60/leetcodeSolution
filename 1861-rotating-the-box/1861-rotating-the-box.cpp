class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            int cell=m-1;
            for(int j=m-1;j>=0;j--){
                if(mat[i][j]=='*'){
                    cell=j-1;
                }
                else if(mat[i][j]=='#'){
                    mat[i][j]='.';
                    mat[i][cell]='#';
                    cell--;
                }
            }
        }
        vector<vector<char>>ans(m,vector<char>(n,'.'));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i][j]=mat[n-1-j][i];
            }
        }
        return ans;
    }
};
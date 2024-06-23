class Solution {
public:
    int minimumArea(vector<vector<int>>& mat) {
        int top,bottom,left,right;
        top=bottom=left=right=-1;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==1){
                    if(top==-1){
                        top=i;
                    }
                    bottom=i;
                }
            }
        }
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++)
            {
                if(mat[i][j]==1){
                    if(left==-1){
                        left=j;
                    }
                    right=j;
                }
            }
        }
        return (right-left+1)*(bottom-top+1);
        
    }
};
class Solution {
public:
    int find(vector<vector<int>>&nums,int n,int m,int i,int j){
        if(i<0||j<0||i>=n||j>=m||nums[i][j]==0) return 0;
        int res=exchange(nums[i][j],0);
        int op1=find(nums,n,m,i+1,j);
        int op2=find(nums,n,m,i-1,j);
        int op3=find(nums,n,m,i,j+1);
        int op4=find(nums,n,m,i,j-1);
        return res+op1+op2+op3+op4;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int maxFish=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    maxFish=max(maxFish,find(grid,n,m,i,j));
                }
            }
        }
        return maxFish;
    }
};
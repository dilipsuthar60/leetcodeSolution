class Solution {
public:
    vector<int>mat[101];
    int dp[101][(1<<10)+1];
    int find(int num,int mask){
        if(num==0) return 0;
        if(dp[num][mask]!=-1) return dp[num][mask];
        int ans=find(num-1,mask);
        for(auto &it:mat[num]){
            if((mask&(1<<it))) continue;
            ans=max(ans,num+find(num-1,mask|(1<<it)));
        }
        return dp[num][mask]= ans;
    }
    int maxScore(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                mat[grid[i][j]].push_back(i);
            }
        }
        return find(100,0);
    }
};
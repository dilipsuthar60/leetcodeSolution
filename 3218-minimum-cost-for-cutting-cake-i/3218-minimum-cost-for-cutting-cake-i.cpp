class Solution {
public:
    int dp[21][21][21][21];
    int find(int rows,int rowe,int cols,int cole,vector<int>&h,vector<int>&v){
        if((rowe-rows)==1&&(cole-cols)==1) return 0;
        int ans=1e9;
        if(dp[rows][rowe][cols][cole]!=-1) return dp[rows][rowe][cols][cole];
        for(int i=rows+1;i<rowe;i++){
            int op1=find(rows,i,cols,cole,h,v);
            int op2=find(i,rowe,cols,cole,h,v);
            ans=min(ans,op1+op2+h[i-1]);
        }
        for(int i=cols+1;i<cole;i++){
            int op1=find(rows,rowe,cols,i,h,v);
            int op2=find(rows,rowe,i,cole,h,v);
            ans=min(ans,op1+op2+v[i-1]);
        }
        return dp[rows][rowe][cols][cole] = ans;
    }
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        memset(dp,-1,sizeof(dp));
        return find(0,m,0,n,horizontalCut,verticalCut);
    }
};
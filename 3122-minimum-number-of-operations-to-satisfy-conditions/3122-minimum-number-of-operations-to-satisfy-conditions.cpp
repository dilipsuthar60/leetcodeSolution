class Solution {
public:
    int dp[1001][11];
    int find(vector<vector<int>>&nums,int n,int m,int index,int prev)
    {
        if(index>=m)
        {
            return 0;
        }
        if(dp[index][prev+1]!=-1) return dp[index][prev+1];
        int ans=1e7;
        for(int i=0;i<=9;i++)
        {
            if(prev!=i)
            {
                ans=min(ans,n-nums[index][i]+find(nums,n,m,index+1,i));
            }
        }
        return dp[index][prev+1] = ans;
    }
    int minimumOperations(vector<vector<int>>& mat) {
        memset(dp,-1,sizeof(dp));
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>nums(m,vector<int>(10,0));
        for(int j=0;j<m;j++)
        {
            for(int i=0;i<n;i++)
            {
                nums[j][mat[i][j]]++;
            }
        }
        return find(nums,n,m,0,-1);
    }
};
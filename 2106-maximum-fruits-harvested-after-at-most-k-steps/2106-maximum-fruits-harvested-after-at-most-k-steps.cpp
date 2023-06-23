class Solution {
public:
    int N=2e5+10;
    int find(vector<vector<int>>&nums,int start,int k)
    {
        vector<int>dp(N,0);
        for(auto it:nums)
        {
            dp[it[0]+1]+=it[1];
        }
        for(int i=1;i<N;i++)
        {
            dp[i]+=dp[i-1];
        }
        int ans=0;
        for(int r=start;r<=min(N-1,start+k);r++)
        {
            int l=min(start,start-(k-2*(r-start)));
            l=max(1,l);
            ans=max(ans,dp[r]-dp[l-1]);
        }
        for(int l=start;l>=max(1,start-k);l--)
        {
            int r=max(l,start+(k-2*(start-l)));
            r=min(N-1,r);
            ans=max(ans,dp[r]-dp[l-1]);
        }
        return ans;
    }
    int maxTotalFruits(vector<vector<int>>&nums, int start, int k) 
    {
        return find(nums,start+1,k);
    }
};
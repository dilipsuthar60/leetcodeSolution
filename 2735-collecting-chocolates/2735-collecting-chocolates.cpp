class Solution {
public:
    long long minCost(vector<int>& nums, int x) 
    {
        vector<int>dp=nums;
        long long cost=1e18;
        for(int i=0,n=nums.size();i<n;i++)
        {
            long long currentCost=1ll*i*x;
            for(int j=0;j<n;j++)
            {
                dp[j]=min(dp[j],nums[(i+j)%n]);
                currentCost+=dp[j];
            }
            cost=min(cost,currentCost);
        }
        return cost;
    }
};
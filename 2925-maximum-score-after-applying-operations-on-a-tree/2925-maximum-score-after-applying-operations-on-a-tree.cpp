class Solution {
public:
    vector<vector<int>>dp;
    long long find(int node,int p,vector<int>&nums)
    {
        long long currentSum=0;
        for(auto it:dp[node])
        {
            if(it!=p)
            {
                currentSum+=find(it,node,nums);
            }
        }
        if(currentSum)
        {
            return min(currentSum,1ll*nums[node]);
        }
        return 1ll*nums[node];
    }
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        dp=vector<vector<int>>(values.size()+1);
        for(auto &it:edges)
        {
            dp[it[0]].push_back(it[1]);
            dp[it[1]].push_back(it[0]);
        }
        long long totalSum=accumulate(values.begin(),values.end(),0ll);
        long long minSum=find(0,-1,values);
        return totalSum-minSum;
    }
};
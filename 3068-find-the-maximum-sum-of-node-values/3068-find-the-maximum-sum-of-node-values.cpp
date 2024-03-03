class Solution {
public:
    vector<vector<long long>>dp;
    void find(vector<vector<int>>&graph,int node,vector<int>&nums,int k,int parent=-1)
    {
        dp[node]={1ll*nums[node],1ll*nums[node]^k};
        for(auto &child:graph[node])
        {
            if(child!=parent)
            {
                find(graph,child,nums,k,node);
                long long n1=max(dp[node][0]+dp[child][0],dp[node][1]+dp[child][1]);
                long long n2=max(dp[node][0]+dp[child][1],dp[node][1]+dp[child][0]);
                dp[node][0]=n1;
                dp[node][1]=n2;
            }
        }
    }
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) 
    {
        int n=nums.size();
        dp=vector<vector<long long>>(n+1,vector<long long>(2,0));
        vector<vector<int>>graph(n);
        for(auto &edge:edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        find(graph,0,nums,k);
        return dp[0][0];
    }
};
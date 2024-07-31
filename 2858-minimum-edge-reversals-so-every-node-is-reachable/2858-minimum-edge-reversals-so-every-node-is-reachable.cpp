class Solution {
public:
    vector<vector<pair<int,int>>>dp;
    int dfs1(int node,vector<int>&vis){
        int sum=0;
        vis[node]=1;
        for(auto &it:dp[node]){
            if(!vis[it.first])
            sum+=it.second+dfs1(it.first,vis);
        }
        return sum;
    }
    void dfs2(int node,vector<int>&ans){
        for(auto &it:dp[node]){
            if(ans[it.first]==-1){
                ans[it.first]=ans[node]+(it.second==1?-1:1);
                dfs2(it.first,ans);
            }
        }
    }
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        dp=vector<vector<pair<int,int>>>(n+10);
        for(auto &it:edges){
            dp[it[0]].push_back({it[1],0});
            dp[it[1]].push_back({it[0],1});
        }
        vector<int>vis(n+1,0);
        int sum=dfs1(0,vis);
        vector<int>ans(n,-1);
        ans[0]=sum;
        dfs2(0,ans);
        return ans;
    }
};
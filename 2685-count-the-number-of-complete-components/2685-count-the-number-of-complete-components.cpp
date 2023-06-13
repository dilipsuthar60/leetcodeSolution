class Solution {
public:
    vector<vector<int>>dp;
    void find(int node,vector<int>&vis,int &cn,int &ce)
    {
        vis[node]=1;
        cn++;
        ce+=dp[node].size();
        for(auto it:dp[node])
        {
            if(!vis[it])
            {
                find(it,vis,cn,ce);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges)
    {
        dp=vector<vector<int>>(n+10);
        for(auto it:edges)
        {
            dp[it[0]].push_back(it[1]);
            dp[it[1]].push_back(it[0]);
        }
        int count=0;
        vector<int>vis(n+10,0);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                int count_node=0;
                int count_edges=0;
                find(i,vis,count_node,count_edges);
                if(count_node*(count_node-1)==count_edges)
                {
                    count++;
                }
            }
        }
        return count;
    }
};
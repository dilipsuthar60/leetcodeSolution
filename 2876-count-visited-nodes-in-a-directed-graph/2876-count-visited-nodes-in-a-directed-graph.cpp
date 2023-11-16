class Solution {
public:
    vector<int>dp[100005];
    vector<int>ans;
    void find(int node,vector<int>&vis,vector<int>&parent,int p=-1)
    {
        parent[node]=p;
        vis[node]=1;
        for(auto it:dp[node])
        {
            if(vis[it]==0)
            {
                find(it,vis,parent,node);
            }
            else if(vis[it]==1)
            {
                vector<int>temp;
                temp.push_back(node);
                int curr=node;
                while(curr!=it)
                {
                    curr=parent[curr];
                    temp.push_back(curr);
                }
                for(int i=0;i<temp.size();i++)
                {
                    ans[temp[i]]=temp.size();
                }
            }
        }
        vis[node]=2;
    }
    int  dfs(int node)
    {
        if(ans[node]!=-1)
        {
            return ans[node];
        }
        int sum=1;
        for(auto it:dp[node])
        {
            sum+=dfs(it);
        }
        return sum;
    }
    vector<int> countVisitedNodes(vector<int>& edges) 
    {
        int n=edges.size();
        ans=vector<int>(n,-1);
        vector<int>vis(n,0);
        vector<int>parent(n,-1);
        for(int i=0;i<n;i++)
        {
            dp[i].push_back(edges[i]);
        }
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                find(i,vis,parent);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(ans[i]==-1)
            {
                ans[i]=dfs(i);
            }
        }
        return ans;
    }
};
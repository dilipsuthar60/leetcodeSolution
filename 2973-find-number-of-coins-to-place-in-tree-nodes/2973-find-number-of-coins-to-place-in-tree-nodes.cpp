class Solution {
public:
    vector<vector<int>>dp;
    vector<int>cost;
    vector<vector<int>>pos;
    vector<vector<int>>neg;
    vector<vector<int>> find(int node,int p=-1)
    {
        vector<int>temp1={cost[node]};
        vector<int>temp2={cost[node]};
        for(auto it:dp[node])
        {
            if(it!=p)
            {
               vector<vector<int>>v=find(it,node);
               for(auto t:v[0])
               {
                   temp1.push_back(t);
               }
                for(auto t:v[1])
                {
                    temp2.push_back(t);
                }
            }
        }
        sort(temp1.rbegin(),temp1.rend());
        sort(temp2.begin(),temp2.end());
        for(int i=0;i<min(3,(int)temp1.size());i++)
        {
            pos[node].push_back(temp1[i]);
        }
        for(int i=0;i<min(3,(int)temp2.size());i++)
        {
            neg[node].push_back(temp2[i]);
        }
        while(temp1.size()>3)
        {
            temp1.pop_back();
        }
        while(temp2.size()>3)
        {
            temp2.pop_back();
        }
        return {temp1,temp2};
    }
    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& Cost) 
    {
        cost=Cost;
        int n=cost.size();
        dp=vector<vector<int>>(n+1);
        pos=vector<vector<int>>(n+1);
        neg=vector<vector<int>>(n+1);
        for(auto it:edges)
        {
            dp[it[0]].push_back(it[1]);
            dp[it[1]].push_back(it[0]);
        }
        vector<long long>ans(n,0);
        find(0);
        for(int i=0;i<n;i++)
        {
            if(pos[i].size()<3)
            {
                ans[i]=1;
            }
            else
            {
                ans[i]=max({ans[i],1ll*pos[i][0]*pos[i][1]*pos[i][2],1ll*pos[i][0]*neg[i][0]*neg[i][1]});
            }
        }
        return ans;
    }
};
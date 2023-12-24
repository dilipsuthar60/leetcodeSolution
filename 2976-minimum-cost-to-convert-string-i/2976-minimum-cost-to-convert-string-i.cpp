class Solution {
public:
    vector<pair<int,int>>dp[50];
    void find(int node,vector<vector<int>>&dis)
    {
        queue<pair<int,int>>q;
        q.push({node,0});
        dis[node][node]=0;
        while(q.size())
        {
            auto [currentnode,cost]=q.front();
            q.pop();
            for(auto it:dp[currentnode])
            {
                if(dis[node][it.first]>dis[node][currentnode]+it.second)
                {
                    dis[node][it.first]=dis[node][currentnode]+it.second;
                    q.push({it.first,dis[node][it.first]});
                }
            }
        }
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        for(int i=0;i<original.size();i++)
        {
            dp[original[i]-'a'].push_back({changed[i]-'a',cost[i]});
        }
        vector<vector<int>>dis(50,vector<int>(50,INT_MAX));
        for(auto it:original)
        {
            find(it-'a',dis);
        }
        long long ans=0;
        for(int i=0;i<source.size();i++)
        {
            if(source[i]==target[i])
            {
                continue;
            }
            int index1=source[i]-'a';
            int index2=target[i]-'a';
            if(dis[index1][index2]==INT_MAX)
            {
                return -1;
            }
            ans+=dis[index1][index2];
        }
        return ans;
    }
};
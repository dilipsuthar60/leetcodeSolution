class Solution {
public:
    using ll=long long;
    void find(vector<pair<ll,ll>>dp[],vector<ll>&dis,ll x,int n)
    {
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
        pq.push({0ll,x});
        vector<int>vis(n,0);
        dis[x]=0ll;
        while(pq.size())
        {
            auto temp=pq.top();
            pq.pop();
            ll cost=temp.first;
            ll node=temp.second;
            if(vis[node])
            {
                continue;
            }
            vis[node]=1;
            for(auto &it:dp[node])
            {
                if(dis[it.first]>dis[node]+it.second)
                {
                    dis[it.first]=dis[node]+it.second;
                    pq.push({dis[it.first],it.first});
                }
            }
        }
    }
    long long minimumWeight(int n, vector<vector<int>>& nums, int src1, int src2, int dest)
    {
        vector<pair<ll,ll>>dp1[n];
        vector<pair<ll,ll>>dp2[n];
        for(auto it:nums)
        {
            dp1[it[0]].push_back({it[1],it[2]});
            dp2[it[1]].push_back({it[0],it[2]});
        }
        vector<ll>dis1(n,1e18),dis2(n,1e18),dis3(n,1e18);
        find(dp1,dis1,src1,n);
        find(dp1,dis2,src2,n);
        find(dp2,dis3,dest,n);
        ll ans=1e18;
        for(int i=0;i<n;i++)
        {
            
            if(dis1[i]==1e18||dis2[i]==1e18||dis3[i]==1e18)
            {
                continue;
            }
            ans=min(ans,dis1[i]+dis2[i]+dis3[i]);
        }
        return ans==1e18?-1:ans;
    }
};
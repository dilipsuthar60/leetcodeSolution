class Solution {
public:
    using pp=pair<long long,long long>;
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& sp) {
        long long n=1e5+1;
        unordered_map<long long,vector<pair<long long,long long>>>dp;
        for(auto &it:sp)
        {
            dp[it[0]*n+it[1]].push_back({it[2]*n+it[3],it[4]});
        }
        priority_queue<pp,vector<pp>,greater<pp>>pq;
        pq.push({0,start[0]*n+start[1]});
        unordered_map<long long,long long>dis;
        dis[start[0]*n+start[1]]=0;
        dp[target[0]*n+target[1]].push_back({0,0});
        while(pq.size())
        {
            auto [d,xy]=pq.top();
            pq.pop();
            if(xy==(target[0]*n+target[1]))
            {
                return d;
            }
            for(auto &[xx,cost]:dp[xy])
            {
                if(!dis.count(xx)||dis[xx]>d+cost)
                {
                    dis[xx]=d+cost;
                    pq.push({d+cost,xx});
                }
            }
            for(auto &[xx,_]:dp)
            {
                int dt=d+abs(xx/n-xy/n)+abs(xx%n-xy%n);
                if(!dis.count(xx)||dis[xx]>dt)
                {
                    dis[xx]=dt;
                    pq.push({dt,xx});
                }
            }
        }
        return -1;
    }
};
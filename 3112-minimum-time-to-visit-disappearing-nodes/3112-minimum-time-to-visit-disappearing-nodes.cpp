class Solution {
public:
    vector<vector<pair<int,int>>>graph;
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        graph=vector<vector<pair<int,int>>>(n+1);
        for(auto &edge:edges){
            graph[edge[0]].push_back({edge[1],edge[2]});
            graph[edge[1]].push_back({edge[0],edge[2]});
        }
        vector<int>dis(n+1,1e8);
        dis[0]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        vector<int>vis(n+1,0);
        while(pq.size())
        {
            auto [currentNodeTime,currentNode] = pq.top();
            pq.pop();
            if(vis[currentNode]) continue;
            vis[currentNode]=1;
            for(auto &[child,time]:graph[currentNode]){
                if(disappear[child]>time+currentNodeTime && dis[child]>time+currentNodeTime)
                {
                    dis[child] = time+currentNodeTime;
                    pq.push({dis[child],child});
                }
            }
        }
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++)
        {
          ans[i]=dis[i]==1e8?-1:dis[i];
        }
        return ans;
    }
};
class Solution {
public:
    vector<int>find(vector<vector<pair<int,int>>>&graph,int n,int start){
        vector<int>dis(n,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,start});
        vector<int>vis(n,0);
        dis[start]=0;
        while(pq.size()){
            auto [cost,node]=pq.top();
            pq.pop();
            if(vis[node]) continue;
            vis[node]=1;
            for(auto &[node,weight]:graph[node]){
                if(dis[node]>cost+weight){
                    dis[node]=cost+weight;
                    pq.push({dis[node],node});
                }
            }
        }
        return dis;
    }
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>graph(n);
        for(auto it:edges){
            graph[it[0]].push_back({it[1],it[2]});
            graph[it[1]].push_back({it[0],it[2]});
        }
        vector<int>from=find(graph,n,0);
        vector<int>end=find(graph,n,n-1);
        vector<bool>result(edges.size(),false);
        int index=0;
        for(auto it:edges){
            int a=it[0];
            int b=it[1];
            int mid=it[2];
            if(from[a]+mid+end[b]==from[n-1]){
                result[index]=true;
            }
            if(from[b]+mid+end[a]==from[n-1]){
                result[index]=true;
            }
            index++;
        }
        return result;
    }
};
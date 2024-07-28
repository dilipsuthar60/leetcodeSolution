class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<int>dp[n+1];
        for(auto edge:edges){
            dp[edge[0]].push_back(edge[1]);
            dp[edge[1]].push_back(edge[0]);
        }
        vector<int>dis1(n+1,1e9);
        vector<int>dis2(n+1,1e9);
        queue<pair<int,int>>pq;
        pq.push({0,1});
        dis1[1]=0;
        while(pq.size()){
            auto [currentTime,node]=pq.front();
            pq.pop();
            if(currentTime>dis2[node]) continue;
            if(node==n&&dis2[node]!=1e9) break;
            int section=currentTime/change;
            if(section&1){
                currentTime=(section+1)*change;
            }
            for(auto &child:dp[node]){
                if(dis1[child]>currentTime+time){
                    dis2[child]=dis1[child];
                    dis1[child]=currentTime+time;
                    pq.push({dis1[child],child});
                }
                else if(dis2[child]>currentTime+time&&dis1[child]!=currentTime+time){
                    dis2[child]=currentTime+time;
                    pq.push({dis2[child],child});
                }
            }
        }
        return dis2[n];
    }
};
class Graph {
public:
    vector<pair<int,int>>dp[200];
    Graph(int n, vector<vector<int>>& edges) {
        for(auto it:edges)
        {
            dp[it[0]].push_back({it[1],it[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        dp[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
            pq.push({0,node1});
        vector<int>dis(20000,INT_MAX);
        vector<int>vis(20000,0);
        dis[node1]=0;
        while(pq.size())
        {
            auto [currentWeight,currentNode]=pq.top();
            pq.pop();
            if(currentNode==node2)
            {
                return dis[node2];
            }
            if(vis[currentNode])
            {
                continue;
            }
            vis[currentNode]=1;
            for(auto [childNode,childWeight]:dp[currentNode])
            {
                if(dis[childNode]>currentWeight+childWeight)
                {
                    dis[childNode]=currentWeight+childWeight;
                    pq.push({dis[childNode],childNode});
                }
            }
        }
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
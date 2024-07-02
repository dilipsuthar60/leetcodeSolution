class Solution {
public:
    pair<int,int> find(vector<vector<int>>&graph,int node,int n){
        vector<int>dis(n+1,-1);
        queue<int>q;
        q.push(node);
        int level=0;
        int farNode=-1;
        while(q.size()){
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                auto temp=q.front();
                q.pop();
                dis[temp]=level;
                farNode=temp;
                for(auto &it:graph[temp]){
                    if(dis[it]==-1)
                      q.push(it);
                }
            }
            level++;
        }
        return {farNode,level-1};
    }
    void createGraph(vector<vector<int>>&graph,vector<vector<int>>& edges){
        for(auto &it:edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n=edges1.size();
        int m=edges2.size();
        vector<vector<int>>graph1(n+1);
        vector<vector<int>>graph2(m+1);
        createGraph(graph1,edges1);
        createGraph(graph2,edges2);
        auto [farNode1,level1] = find(graph1,0,n);
        auto [Node1,diameter1] =find(graph1,farNode1,n);
        auto [farNode2,level2] = find(graph2,0,m);
        auto [Node2,diameter2] =find(graph2,farNode2,m);
        cout<<diameter1<<"  "<<diameter2<<endl;
        return max({diameter1,diameter2,(diameter1+1)/2+(diameter2+1)/2+1});
    }
};
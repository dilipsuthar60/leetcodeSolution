class Solution {
public:
    int find(vector<vector<int>>&graph,int node,int &diameter,int parent=-1){
        int max1,max2;
        max1=max2=0;
        for(auto &it:graph[node]){
            if(parent!=it){
                int current =find(graph,it,diameter,node);
                if(current>=max1){
                    max2=max1;
                    max1=current;
                }
                else if(current>=max2){
                    max2=current;
                }
            }
        }
        diameter=max(diameter,max1+max2);
        return max(max1,max2)+1;
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
        int diameter1=0;
        int diameter2=0;
        find(graph1,0,diameter1);
        find(graph2,0,diameter2);
        return max({diameter1,diameter2,(diameter1+1)/2+(diameter2+1)/2+1});
    }
};
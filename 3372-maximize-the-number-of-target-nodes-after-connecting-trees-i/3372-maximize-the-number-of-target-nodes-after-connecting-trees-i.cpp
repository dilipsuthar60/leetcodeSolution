class Solution {
public:
    // step 1. create graph give edges 
    vector<vector<int>>createGraph(vector<vector<int>>&edges){
        int n=edges.size();
        vector<vector<int>>graph(n+1);
        for(auto &edge:edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        return graph;
    }
    int countNodes(vector<vector<int>>&edges,int node,int k,int p=-1){
        if(k<0){
            return 0;
        }
        int count=1;
        for(auto &child:edges[node]){
            if(p!=child){
                count+=countNodes(edges, child, k-1, node);
            }
        }
        return count;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n=edges1.size();
        int m=edges2.size();
        auto graph1=createGraph(edges1);
        auto graph2=createGraph(edges2);
        int maxNodeCount=0;
        for(int i=0;i<=m;i++){
            maxNodeCount=max(maxNodeCount,countNodes(graph2,i,k-1));
        }
        vector<int>ans;
        for(int i=0;i<=n;i++){
            int value=maxNodeCount+countNodes(graph1,i,k);
            ans.push_back(value);
        }
        return ans;
    }
};
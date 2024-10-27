class Solution {
public:
    vector<vector<int>>graph;
    void find(int node,vector<int>&subtree,int p=-1){
        for(auto &it:graph[node]){
            if(it!=p){
                find(it,subtree,node);
                subtree[node]+=subtree[it];
            }
        }
    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n=s.size();
        graph=vector<vector<int>>(n+1);
        vector<int>newParent(n,-1);
        for(int i=0;i<n;i++){
            int currentNode=parent[i];
            while(currentNode!=-1&&s[currentNode]!=s[i]){
                currentNode=parent[currentNode];
            }
            newParent[i]=currentNode!=-1?currentNode:parent[i];
        }
        for(int i=0;i<n;i++){
            if(newParent[i]!=-1){
                graph[newParent[i]].push_back(i);
            }
        }
        vector<int>subtree(n,1);
        find(0,subtree);
        return subtree;
    }
};
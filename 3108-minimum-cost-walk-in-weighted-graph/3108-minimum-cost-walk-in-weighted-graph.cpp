class Solution {
public:
    vector<int>parent;
    vector<int>weight;
    vector<int>rank;
    int find(int x,int y){
        if(getParent(x)!=getParent(y)) return -1;
        return weight[getParent(x)];
    }
    void merge(int x,int y,int wt){
        x=getParent(x);
        y=getParent(y);
        weight[x]=weight[y]=(wt&weight[x]&weight[y]);
        if(rank[x]<rank[y]){
            parent[x]=y;
        }
        else if(rank[x]>rank[y]){
            parent[x]=y;
        }
        else{
            parent[x]=y;
            rank[x]++;
        }
    }
    int getParent(int x){
        if(parent[x]==x) return x;
        return parent[x] = getParent(parent[x]);
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& querys) {
        weight=vector<int>(n+10,(1<<30)-1);
        parent=vector<int>(n+10);
        rank=vector<int>(n+10);
        
        for(int i=0;i<n;i++) parent[i]=i;
        for(auto edge:edges){
            merge(edge[0],edge[1],edge[2]);
        }
        vector<int>result;
        for(auto query:querys){
            result.push_back(find(query[0],query[1]));
        }
        return result;
    }
};
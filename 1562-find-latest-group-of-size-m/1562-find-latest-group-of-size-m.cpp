class Solution {
public:
    vector<int>parent;
    vector<int>size;
    vector<int>group;
    int find(int x){
        if(x==parent[x]) return x;
        return parent[x]=find(parent[x]);
    }
    void merge(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y) return ;
        group[size[x]]--;
        group[size[y]]--;
        size[y]+=size[x];
        parent[x]=y;
        size[x]=0;
        group[size[y]]++;
    }
    int findLatestStep(vector<int>& arr, int m) {
        int n=arr.size();
        parent.resize(n+10);
        size.resize(n+10);
        group.resize(n+10);
        vector<int>vis(n+1,0);
        for(int i=0;i<n+5;i++){
            parent[i]=i;
            size[i]=1;
        }
        int step=-1;
        for(int i=0;i<n;i++){
            int x=arr[i]-1;
            group[1]++;
            vis[x]=1;
            // for(int i=0;i<n;i++){
            //     cout<<group[i]<<" ";
            // }
            // cout<<endl;
            // for(int i=0;i<n;i++){
            //     cout<<size[i]<<" ";
            // }
            // cout<<endl<<endl<<endl;
            if(x+1<n&&vis[x+1]){
                merge(x,x+1);
            }
            if(x-1>=0&&vis[x-1]){
                merge(x,x-1);
            }
            if(group[m]){
                step=i+1;
            }
        }
        return step;
    }
};
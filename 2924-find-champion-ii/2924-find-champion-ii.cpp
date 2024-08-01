class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        int indegree[n];
        memset(indegree,0,sizeof(indegree));
        for(auto &it:edges){
            indegree[it[1]]++;
        }
        int ans=-1;
        int count=0;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                ans=i;
                count++;
            }
        }
        return count>1?-1:ans;
    }
};
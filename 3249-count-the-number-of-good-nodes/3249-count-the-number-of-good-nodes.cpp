class Solution {
public:
    vector<int>dp[100005];
    int ans=0;
    void find(int node,vector<int>&subtree,int p=-1){
        unordered_map<int,int>mp;
        for(auto &it:dp[node]){
            if(it!=p){
                find(it,subtree,node);
                subtree[node]+=subtree[it];
                mp[subtree[it]]++;
            }
        }
        if(mp.size()<=1){
            ans++;
        }
    }
    int countGoodNodes(vector<vector<int>>& edges) {
        int n=edges.size()+2;
        for(auto &it:edges){
            dp[it[0]].push_back(it[1]);
            dp[it[1]].push_back(it[0]);
        }
        vector<int>subtree(n,1);
        find(0,subtree);
        return ans;
    }
};
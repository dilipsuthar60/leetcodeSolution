class Solution {
public:
    vector<int>dp[100005];
    void find(int node,vector<int>&vis){
        vis[node]=1;
        for(auto &it:dp[node]){
            if(!vis[it]){
                find(it,vis);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        for(auto &it:invocations){
            dp[it[0]].push_back(it[1]);
        }
        vector<int>vis(n,0);
        find(k,vis);
        bool isSuspicious=true;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                for(auto &it:dp[i]){
                    if(vis[it]){
                        isSuspicious=false;
                    }
                }
            }
        }
        vector<int>ans;
        if(isSuspicious){
            for(int i=0;i<n;i++){
                if(!vis[i]){
                   ans.push_back(i); 
                }
            }
        }
        else{
            for(int i=0;i<n;i++){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
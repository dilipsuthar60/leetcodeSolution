class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<int>dp[n+1];
        for(auto &it:edges){
            dp[it[0]].push_back(it[1]);
            dp[it[1]].push_back(it[0]);
        }
        queue<int>q;
        q.push(0);
        vector<int>vis(n,0);
        for(auto it:restricted){
            vis[it]=1;
        }
        vis[0]=1;
        while(q.size()){
            auto temp=q.front();
            q.pop();
            for(auto it:dp[temp]){
                if(vis[it]==0){
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            count+=vis[i];
        }
        return count-restricted.size();
    }
};
class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& q) {
        vector<int>dp[n+1];
        for(int i=0;i<n-1;i++){
            dp[i].push_back(i+1);
        }
        vector<int>ans(q.size(),0);
        for(int i=0;i<q.size();i++){
            int u=q[i][0];
            int v=q[i][1];
            dp[u].push_back(v);
            queue<int>q;
            q.push(0);
            vector<int>vis(n,0);
            vis[0]=1;
            int level=0;
            int flag=0;
            while(q.size()){
                int size=q.size();
                for(int j=0;j<size;j++){
                    auto temp=q.front();
                    q.pop();
                    if(temp==n-1){
                        flag=1;
                        break;
                    }
                    for(auto &it:dp[temp]){
                        if(vis[it]==0){
                            vis[it]=1;
                            q.push(it);
                        }
                    }
                }
                if(flag) break;
                level++;
            }
            ans[i]=level;
        }
        return ans;
    }
};
class Solution {
public:
    vector<int>dp[40005];
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        for(auto &it:paths){
            dp[it[0]-1].push_back(it[1]-1);
            dp[it[1]-1].push_back(it[0]-1);
        }
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]!=-1) continue;
            queue<int>q;
            color[i]=1;
            q.push(i);
            while(q.size()){
                auto temp=q.front();
                q.pop();
                for(auto&child:dp[temp]){
                    if(color[child]==-1){
                        color[child]=max(1,(color[temp]+1)%5);
                        q.push(child);
                    }
                    else if(color[child]==color[temp]){
                        color[child]=max(1,(color[temp]+1)%5);
                    }
                }
            }
        }
        return color;
    }
};
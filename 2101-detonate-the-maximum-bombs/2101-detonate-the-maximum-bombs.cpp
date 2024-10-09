class Solution {
public:
    vector<int>dp[201];
    // get distance between two circle;
    long long getDistance(int x1,int y1,int x2,int y2){
        long long diffX=abs(x1-x2);
        long long diffY=abs(y1-y2);
        return diffX*diffX+diffY*diffY;
    }
    bool isInside(vector<int>&point1,vector<int>&point2){
        return 1ll*point1[2]*point1[2]>=getDistance(point1[0],point1[1],point2[0],point2[1]);
    }
    int dfs(int node,vector<int>&vis){
        vis[node]=1;
        int count=1;
        for(auto &child:dp[node]){
            if(!vis[child]){
                count+=dfs(child, vis);
            }
        }
        return count;
    }
    int maximumDetonation(vector<vector<int>>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(isInside(nums[i],nums[j])){
                    dp[i].push_back(j);
                }
            }
        }
        int ans=0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            vector<int>vis(n,0);
            ans=max(ans,dfs(i,vis));
        }
        return ans;
    }
};
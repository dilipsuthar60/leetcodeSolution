class Solution {
public:
    unordered_set<int>vis;
    int dp[3001][3001];
    int find(string &s,string &p,int i,int j){
        if(i>=s.size()) return j==p.size()?0:-1e8;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=find(s,p,i+1,j);
        if(vis.find(i)!=vis.end()){
            ans=max(ans,1+find(s,p,i+1,j));
        }
        if(j<p.size()&&s[i]==p[j]){
            ans=max(ans,find(s,p,i+1,j+1));
        }
        return dp[i][j]= ans;
    }
    int maxRemovals(string source, string pattern, vector<int>& targetIndices){
        for(auto &it:targetIndices) vis.insert(it);
        memset(dp,-1,sizeof(dp));
        return find(source,pattern,0,0);
    }
};

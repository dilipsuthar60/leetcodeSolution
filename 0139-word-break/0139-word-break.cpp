class Solution {
public:
    unordered_set<string>vis;
    int dp[304];
    bool find(string &s,int index){
        if(index>=s.size()){
            return true;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        for(int i=index;i<s.size();i++){
            if(vis.find(s.substr(index,i-index+1))!=vis.end()&&find(s,i+1)){
                return true;
            }
        }
        return dp[index]= false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp,-1,sizeof(dp));
        for(auto &it:wordDict){
            vis.insert(it);
        }
        return find(s,0);
    }
};
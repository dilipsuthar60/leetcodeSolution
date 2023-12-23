class Solution {
public:
    unordered_set<string>vis;
    int dp[51];
    int find(string &s,int index)
    {
        if(index>=s.size())
        {
            return 0;
        }
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        int ans=0;
        string str="";
        for(int i=index;i<s.size();i++)
        {
            str.push_back(s[i]);
            if(vis.find(str)!=vis.end())
            {
                ans=max(ans,(int)str.size()+find(s,i+1));
            }
        }
        ans=max(ans,find(s,index+1));
        return dp[index] = ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        for(auto it:dictionary){
            vis.insert(it);
        }
        memset(dp,-1,sizeof(dp));
        return s.size()-find(s,0);
    }
};
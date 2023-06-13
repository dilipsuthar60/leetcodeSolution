class Solution {
public:
    unordered_set<string>st;
    int dp[60];
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
        string curr="";
        for(int i=index;i<s.size();i++)
        {
            curr.push_back(s[i]);
            if(st.find(curr)!=st.end())
            {
              ans=max(ans,(int)curr.size()+find(s,i+1));
            }
        }
        ans=max(ans,find(s,index+1));
        return dp[index]= ans;
    }
    int minExtraChar(string s, vector<string>& dic) {
        for(auto it:dic)
        {
            st.insert(it);
        }
        memset(dp,-1,sizeof(dp));
        int val=find(s,0);
        return s.size()-val;
    }
};
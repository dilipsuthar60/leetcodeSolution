class Solution {
public:
    bool hammingDistance(string&s1,string&s2)
    {
        if(s1.size()!=s2.size()) return false;
        int count=0;
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]!=s2[i]) count++;
            if(count>1) return false;
        }
        return true;
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n=words.size();
        vector<vector<string>>dp(n);
        int maxElement=0;
        for(int i=0;i<n;i++)
        {
            dp[i].push_back(words[i]);
            for(int j=0;j<i;j++)
            {
                if(hammingDistance(words[i],words[j])&&groups[i]!=groups[j]&&dp[j].size()+1>dp[i].size())
                {
                    dp[i]=dp[j];
                    dp[i].push_back(words[i]);
                }
            }
            maxElement=max(maxElement,(int)dp[i].size());
        }
        for(int i=0;i<n;i++)
        {
            if(maxElement==dp[i].size())
            {
                return dp[i];
            }
        }
        // cout<<value<<endl;
        return {};
    }
};
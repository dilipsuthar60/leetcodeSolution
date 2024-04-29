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
        int maxElement=0;
        vector<int>dp(n,1);
        vector<int>parent(n,-1);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(hammingDistance(words[i],words[j])&&groups[i]!=groups[j]&&dp[j]+1>dp[i])
                {
                    dp[i]=dp[j]+1;
                    parent[i]=j;
                }
            }
            maxElement=max(maxElement,(int)dp[i]);
        }
        int maxIndex=-1;
        for(int i=0;i<n;i++)
        {
            if(maxElement==dp[i])
            {
                maxIndex=i;
            }
        }
        vector<string>result;
        while(maxIndex!=-1)
        {
            result.push_back(words[maxIndex]);
            maxIndex=parent[maxIndex];
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
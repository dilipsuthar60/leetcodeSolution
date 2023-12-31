class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) 
    {
        int ans=-1;
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++)
        {
            if(mp.find(s[i])!=mp.end())
            {
                ans=max(ans,i-mp[s[i]]-1);
            }
            else
            {
                mp[s[i]]=i;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int minimizedStringLength(string s)
    {
        unordered_map<int,int>mp;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
        }
        return mp.size();
    }
};
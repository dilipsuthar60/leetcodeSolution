class Solution {
public:
    string lastNonEmptyString(string s) 
    {
        int n=s.size();
        unordered_map<char,vector<int>>mp;
        int maxFrequency=0;
        for(int index=0;index<n;index++)
        {
            mp[s[index]].push_back(index);
            maxFrequency=max(maxFrequency,(int)mp[s[index]].size());
        }
        vector<int>secondLastCharacterIndex;
        for(auto &[_,v]:mp)
        {
            if(v.size()==maxFrequency)
            secondLastCharacterIndex.push_back(v.back());
        }
        sort(secondLastCharacterIndex.begin(),secondLastCharacterIndex.end());
        string result="";
        for(auto &index:secondLastCharacterIndex)
        {
            result+=s[index];
        }
        return result;
    }
};
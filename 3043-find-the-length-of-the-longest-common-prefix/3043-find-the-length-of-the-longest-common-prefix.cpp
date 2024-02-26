class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string,int>mp;
        for(auto &it:arr1)
        {
            string s=to_string(it);
            for(int i=0;i<s.size();i++)
            {
                mp[s.substr(0,i+1)]++;
            }
        }
        int ans=0;
        for(auto &it:arr2)
        {
            string s=to_string(it);
            for(int i=0;i<s.size();i++)
            {
                if(mp.find(s.substr(0,i+1))!=mp.end()) ans=max(ans,i+1);
            }
        }
        return ans;
    }
};
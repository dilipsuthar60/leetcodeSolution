class Solution {
public:
    int k;
    bool find(string &s,int &window,unordered_map<string,int>mp)
    {
        for(int i=0;i<s.size();i+=window)
        {
            string str=s.substr(i,window);
            if(--mp[str]==-1)
            {
                return false;
            }
        }
        return true;
    }
    vector<int> findSubstring(string s, vector<string>& words) 
    {
        unordered_map<string,int>mp,new_map;
        int first_len=words[0].size();
        if(first_len>s.size()) return {};
        k=words[0].size()*(words.size());
        for(auto &it:words)
        {
            mp[it]++;
        }
        vector<int>ans;
        for(int i=0;i<s.size()-k+1;i++)
        {
            string str=s.substr(i,k);
            if(find(str,first_len,mp))
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
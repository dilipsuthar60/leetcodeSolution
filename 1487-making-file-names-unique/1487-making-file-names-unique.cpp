class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string,int>mp;
        vector<string>ans;
        for(auto it:names){
            string s=it;
            int index=mp[s];
            while(mp[s]>0){
                s=it+"("+to_string(index++)+")";
                mp[it]=index;
            }
            ans.push_back(s);
            mp[s]++;
        }
        return ans;
    }
};
class Solution {
public:
    void find(int node,unordered_map<int,vector<int>>&mp,vector<int>&ans,unordered_set<int>&s)
    {
        s.insert(node);
        ans.push_back(node);
        for(auto &it:mp[node])
        {
            if(s.find(it)==s.end())
            {
                find(it,mp,ans,s);
            }
        }
    }
    vector<int> restoreArray(vector<vector<int>>& nums) 
    {
        unordered_map<int,vector<int>>mp;
        int n=nums.size();
        for(auto &it:nums)
        {
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);
        }
        vector<int>ans;
        unordered_set<int>vis;
        int node=INT_MAX;
        for(auto &it:mp)
        {
            if(it.second.size()==1)
            {
                node=min(it.first,node);
                // break;
            }
        }
        find(node,mp,ans,vis);
        return ans;
    }
};
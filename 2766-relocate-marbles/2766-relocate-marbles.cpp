class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        unordered_map<int,int>mp;
        for(auto it:nums)
        {
            mp[it]=it;
        }
        for(int i=0;i<moveFrom.size();i++)
        {
            if(mp.find(moveFrom[i])!=mp.end())
            {
                mp[moveFrom[i]]=0;
                mp[moveTo[i]]=moveTo[i];
            }
        }
        vector<int>ans;
        for(auto &[a,b]:mp)
        {
            if(b)
            ans.push_back(b);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
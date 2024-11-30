class Solution {
public:
     unordered_map<int,vector<int>>dp;
     unordered_map<int,int>in,out;
    void find(int node,vector<vector<int>>&ans)
    {
        while(dp[node].size()!=0)
        {
            auto &it=dp[node];
            int next_node=dp[node].back();
            dp[node].pop_back();
            find(next_node,ans);
            ans.push_back({node,next_node});
        }
    }
    vector<vector<int>>validArrangement(vector<vector<int>>&nums) 
    {
        unordered_set<int>s;
        for(auto&it:nums)
        {
            s.insert(it[0]);
            s.insert(it[1]);
            dp[it[0]].push_back(it[1]);
            in[it[1]]++;
            out[it[0]]++;
        }
        int start=-1;
        for(auto it:s)
        {
            if(out[it]-in[it]==1)
            {
                start=it;
                break;
            }
        }
        if(start==-1)
        {
            start=nums[0][0];
        }
        vector<vector<int>>ans;
        find(start,ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
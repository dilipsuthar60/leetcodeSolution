class Solution {
public:
    int maximumScore(vector<int>& nums, vector<vector<int>>& edges) 
    {
        int n=nums.size();
        set<pair<int,int>>dp[n+1];
        for(auto &it:edges)
        {
            int a=it[0];
            int b=it[1];
            dp[a].insert({nums[b],b});
            dp[b].insert({nums[a],a});
            if(dp[a].size()>3)
            {
                dp[a].erase(dp[a].begin());
            }
            if(dp[b].size()>3)
            {
                dp[b].erase(dp[b].begin());
            }
        }
        auto check=[&](int a,int b,int c,int d)
        {
            return (a!=c)&&(a!=d)&&(b!=c)&&(b!=d)&&(c!=d);
        };
        int ans=-1;
        for(auto &it:edges)
        {
            int a=it[0];
            int b=it[1];
            for(auto &t1:dp[a])
            {
                for(auto &t2:dp[b])
                {
                    if(check(a,b,t1.second,t2.second))
                    {
                        ans=max(ans,nums[a]+nums[b]+t1.first+t2.first);
                    }
                }
            }
        }
        return ans;
    }
};
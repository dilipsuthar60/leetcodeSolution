class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) 
    {
        int n=nums.size();
        vector<long long>prefix(n+1,0);
        for(int i=0;i<n;i++)
        {
            prefix[i+1]=prefix[i]+nums[i];
        }
        long long ans=-1e18;
        unordered_map<long long,long long>mp;
        for(int i=0;i<n;i++)
        {
            if(mp.find(nums[i]-k)!=mp.end())
            {
                ans=max(ans,prefix[i+1]-mp[nums[i]-k]);
            }
            if(mp.find(nums[i]+k)!=mp.end())
            {
                 ans=max(ans,prefix[i+1]-mp[nums[i]+k]);
            }
            if(mp.find(nums[i])==mp.end())
            {
                mp[nums[i]]=prefix[i];
            }
            else{
                mp[nums[i]]=min(mp[nums[i]],prefix[i]);
            }
        }
        if(ans==-1e18)
        {
            return 0;
        }
        return ans;
    }
};
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) 
    {
        int n=nums.size();
        long long sum=0;
        long long ans=-1e18;
        unordered_map<long long,long long>mp;
        for(int i=0;i<n;i++)
        {
            if(mp.find(nums[i])==mp.end())
            {
                mp[nums[i]]=sum;
            }
            else{
                mp[nums[i]]=min(mp[nums[i]],sum);
            }
            sum+=nums[i];
            if(mp.find(nums[i]-k)!=mp.end())
            {
                ans=max(ans,sum-mp[nums[i]-k]);
            }
            if(mp.find(nums[i]+k)!=mp.end())
            {
                 ans=max(ans,sum-mp[nums[i]+k]);
            }
        }
        if(ans==-1e18)
        {
            return 0;
        }
        return ans;
    }
};
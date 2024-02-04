class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans=0;
        int n=nums.size();
        long long currentSum=0;
        unordered_map<int,long long>mp;
        for(int i=0;i<k;i++)
        {
            currentSum+=nums[i];
            mp[nums[i]]++;
        }
        if(mp.size()==k)
        {
            ans=max(ans,currentSum);
        }
        for(int i=k;i<n;i++)
        {
            currentSum-=nums[i-k];
            currentSum+=nums[i];
            if(--mp[nums[i-k]]==0){
                mp.erase(nums[i-k]);
            }
            mp[nums[i]]++;
            if(mp.size()==k)
            {
                ans=max(ans,currentSum);
            }
        }
        return ans;
    }
};
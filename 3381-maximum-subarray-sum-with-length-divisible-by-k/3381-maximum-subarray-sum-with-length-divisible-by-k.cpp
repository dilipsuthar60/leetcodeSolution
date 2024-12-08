class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<long long,long long>mp;
        long long sum=0;
        long long ans=-1e18;
        mp[0]=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(mp.find((i+1)%k)!=mp.end()){
                ans=max(ans,sum-mp[(i+1)%k]);
            }
            if(mp.count((i+1)%k)){
                mp[(i+1)%k]=min(mp[(i+1)%k],sum);
            }
            else{
                mp[(i+1)%k]=sum;
            }
        }
        return ans;
    }
};
class Solution {
public:
    const int mod = 1e9+7;
    int sumOfGoodSubsequences(vector<int>& nums) {
        int n=nums.size();
        vector<long long>left(n,0),right(n,0);
        unordered_map<int,long long>mp;
        for(int i=0;i<n;i++){
            long long count=mp[nums[i]-1]+mp[nums[i]+1]+1;
            left[i]=count%mod;
            mp[nums[i]]=(mp[nums[i]]+count)%mod;
        }
        mp.clear();
        for(int i=n-1;i>=0;i--){
            long long count=mp[nums[i]-1]+mp[nums[i]+1]+1;
            right[i]=count%mod;
            mp[nums[i]]=(mp[nums[i]]+count)%mod;
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            ans+=(((left[i]*right[i])%mod)*(nums[i]%mod));
            ans%=mod;
        }
        return ans;
    }
};
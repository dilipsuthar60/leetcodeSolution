class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n=nums.size();
        unordered_map<int,long long>mp;
        mp.insert({0,1});
        long long sum=0;
        long long count=0;
        for(int i=0;i<n;i++){
            sum+=(nums[i]%modulo==k)?1:0;
            sum%=modulo;
            int need=(sum-k+modulo)%modulo;
            count+=mp[need];
            mp[sum]++;
        }
        return count;
    }
};
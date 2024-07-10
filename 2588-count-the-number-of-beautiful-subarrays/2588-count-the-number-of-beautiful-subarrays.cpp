class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        long long ans=0;
        unordered_map<long long,long long>mp;
        long long curr=0;
        mp[0]=1;
        for(auto it:nums){
            curr^=it;
            ans+=mp[curr];
            mp[curr]++;
        }
        return ans;
    }
};
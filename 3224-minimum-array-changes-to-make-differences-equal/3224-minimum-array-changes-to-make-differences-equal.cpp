class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        vector<int>limit;
        for(int i=0;i<n/2;i++){
            int a=nums[i];
            int b=nums[n-i-1];
            mp[abs(a-b)]++;
            limit.push_back(max({a,b,k-min(a,b)}));
        }
        sort(limit.begin(),limit.end());
        int ans=n/2;
        n/=2;
        for(auto &[diff,freq]:mp){
            int remaning=n-freq;
            int greater=lower_bound(limit.begin(),limit.end(),diff)-limit.begin();
            ans=min(ans,remaning+greater);
        }
        return ans;
    }
};
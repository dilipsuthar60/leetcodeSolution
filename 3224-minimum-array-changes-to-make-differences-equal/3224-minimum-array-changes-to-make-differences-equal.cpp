class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>mp(k+1,0);
        vector<int>limit;
        for(int i=0;i<n/2;i++){
            int a=nums[i];
            int b=nums[n-i-1];
            mp[abs(a-b)]++;
            int threshold = max(max(a, b), k - min(a, b));
            limit.push_back(threshold);
        }
        sort(limit.begin(),limit.end());
        int ans=n/2;
        n/=2;
        for(int i=0;i<=k;i++){
            int remaning=n-mp[i];
            int greater=lower_bound(limit.begin(),limit.end(),i)-limit.begin();
            ans=min(ans,remaning+greater);
        }
        return ans;
    }
};
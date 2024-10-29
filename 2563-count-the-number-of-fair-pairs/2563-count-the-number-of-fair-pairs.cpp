class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0,n=nums.size();i<n;i++){
            long long left=lower_bound(nums.begin()+i+1,nums.end(),lower-nums[i])-nums.begin();
            long long right=upper_bound(nums.begin()+i+1,nums.end(),upper-nums[i])-nums.begin();
            ans+=(right-left);
        }
        return ans;
    }
};
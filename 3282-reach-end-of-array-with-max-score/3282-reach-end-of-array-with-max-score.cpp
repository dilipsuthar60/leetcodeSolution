class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        int n = nums.size();
        int currentMax=nums.front();
        long long ans=0;
        for(int i=1;i<n;i++){
            ans+=currentMax;
            currentMax=max(currentMax,nums[i]);
        }
        return ans;
    }
};
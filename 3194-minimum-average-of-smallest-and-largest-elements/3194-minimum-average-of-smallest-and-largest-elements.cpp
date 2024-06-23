class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        double ans=1e9;
        for(int i=0;i<n/2;i++){
            ans=min(ans,(nums[i]+nums[n-i-1])/2.0);
        }
        return ans;
    }
};
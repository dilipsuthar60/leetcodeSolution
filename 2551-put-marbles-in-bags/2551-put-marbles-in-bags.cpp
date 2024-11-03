class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n=weights.size();
        vector<long long>nums;
        for(int i=0;i<n-1;i++){
            nums.push_back(weights[i]+weights[i+1]);
        }
        sort(nums.begin(),nums.end());
        long long minSum=0;
        long long maxSum=0;
        for(int i=0;i<k-1;i++){
            minSum+=nums[i];
            maxSum+=nums[nums.size()-i-1];
        }
        return maxSum-minSum;
    }
};
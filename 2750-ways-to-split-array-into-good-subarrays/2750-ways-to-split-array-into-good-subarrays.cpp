class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int n=nums.size();
        vector<int>ones;
        for(int i=0;i<n;i++){
            if(nums[i]) ones.push_back(i);
        }
        if(ones.size()==0) return 0;
        const int mod=1e9+7;
        long long result=1;
        for(int i=0;i<ones.size()-1;i++){
            result*=(ones[i+1]-ones[i]);
            result%=mod;
        }
        return result;
    }
};
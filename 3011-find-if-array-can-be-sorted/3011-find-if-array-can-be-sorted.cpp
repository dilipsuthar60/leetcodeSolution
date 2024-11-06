class Solution {
public:
    int getSetBits(int n){
        return __builtin_popcount(n);
    }
    bool canSortArray(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                if(getSetBits(nums[j])==getSetBits(nums[j-1])&&nums[j]<nums[j-1]){
                    swap(nums[j],nums[j-1]);
                }
            }
        }
        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i]) return false;
        }
        return true;
    }
};
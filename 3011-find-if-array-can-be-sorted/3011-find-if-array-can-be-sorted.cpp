class Solution {
public:
    int getBitCount(int n){
        return __builtin_popcount(n);
    }
    bool canSortArray(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++)
            {
                if(getBitCount(nums[j])==getBitCount(nums[j-1])&&nums[j]<nums[j-1]){
                    swap(nums[j],nums[j-1]);
                }
            }
        }
        if(is_sorted(nums.begin(),nums.end())) return true;
        return false;
    }
};
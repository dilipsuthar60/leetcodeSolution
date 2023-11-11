class Solution {
public:
    int maxProductDifference(vector<int>& nums) 
    {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int val1=nums[n-1]*nums[n-2];
        int val2=nums[0]*nums[1];
        return val1-val2;
    }
};
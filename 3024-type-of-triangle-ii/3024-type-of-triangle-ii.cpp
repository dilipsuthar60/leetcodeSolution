class Solution {
public:
    string triangleType(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums[0]+nums[1]<=nums[2])
        {
            return "none";
        }
        if(nums[0]!=nums[1]&&nums[1]!=nums[2]&&nums[2]!=nums[0])
        {
            return "scalene";
        }
        if(nums[0]==nums[1]&&nums[1]==nums[2])
        {
            return "equilateral";
        }
        return (nums[0]==nums[1]||nums[1]==nums[2])?"isosceles":"none";
    }
};
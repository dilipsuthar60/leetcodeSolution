class Solution {
public:
    int minNumberOperations(vector<int>& nums)
    {
        int count=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            count+=max(nums[i]-nums[i-1],0);
        }
        return count;
    }
};
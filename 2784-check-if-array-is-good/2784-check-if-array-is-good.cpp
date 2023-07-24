class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int size=nums.size();
        if(nums.size()<2)
        {
            return false;
        }
        for(int i=0;i<size-2;i++)
        {
            if(nums[i]!=i+1)
            {
                return false;
            }
        }
        return (nums[size-1]==nums[size-2])&&(nums[size-2]==size-1);
    }
};
class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int result=0;
        int currentAnd=-1;
        for(int i=0;i<nums.size();i++)
        {
            currentAnd&=nums[i];
            if(currentAnd==0)
            {
                result++;
                currentAnd=-1;
            }
        }
        return result?result:1;
    }
};
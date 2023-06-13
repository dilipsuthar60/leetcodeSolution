class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        int mini=*min_element(nums.begin(),nums.end());
        if(maxi==mini)
        {
            return -1;
        }
        int ans=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(maxi!=nums[i]&&mini!=nums[i])
            {
                ans=nums[i];
            }
        }
        return ans;
    }
};
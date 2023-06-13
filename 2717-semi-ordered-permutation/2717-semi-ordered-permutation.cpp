class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) 
    {
        int n=nums.size();
        int index1=0;
        int index2=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                index1=i;
            }
            if(nums[i]==nums.size())
            {
                index2=i;
            }
        }
        if(index1<index2)
        {
            return  index1+(n-index2-1);
        }
        return index1+(n-index2-1)-1;
    }
};
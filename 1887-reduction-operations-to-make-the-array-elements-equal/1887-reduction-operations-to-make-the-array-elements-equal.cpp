class Solution {
public:
    int reductionOperations(vector<int>& nums) 
    {
        int ans=0;
        int n=nums.size();
        sort(nums.rbegin(),nums.rend());
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]!=nums[i])
            {
                ans+=i;
            }
        }
        return ans;
    }
};
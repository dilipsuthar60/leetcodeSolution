class Solution {
public:
    int largestCombination(vector<int>& nums)
    {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<32;i++)
        {
            int count=0;
            for(int j=0;j<n;j++)
            {
                if(nums[j]&(1<<i))
                {
                    count++;
                }
            }
            ans=max(ans,count);
        }
        return ans;
    }
};
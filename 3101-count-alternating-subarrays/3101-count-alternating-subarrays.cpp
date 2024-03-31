class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long ans=0;
        long long count=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=nums[i-1])
            {
                count++;
            }
            else
            {
                ans+=(count*(count+1)/2);
                count=1;
            }
        }
        ans+=(count*(count+1)/2);
        return ans;
    }
};
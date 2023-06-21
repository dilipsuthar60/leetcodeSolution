class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=1e9+182;
        for(int i=0;i<n;i++)
        {
            if(i)
            {
                ans=min(ans,nums[i]-nums[i-1]);
            }
        }
        return ans;
    }
};
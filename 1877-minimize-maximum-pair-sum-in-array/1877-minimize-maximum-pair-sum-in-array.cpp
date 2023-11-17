class Solution {
public:
    int minPairSum(vector<int>& nums)
    {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int l=0;
        int r=n-1;
        int ans=INT_MIN;
        while(l<r)
        {
            ans=max(ans,nums[l]+nums[r]);
            l++;
            r--;
        }
        return ans;
    }
};
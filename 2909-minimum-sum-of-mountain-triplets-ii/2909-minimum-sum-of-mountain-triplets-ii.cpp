class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n=nums.size();
        int ans=1e9;
        vector<int>suffix(n,0);
        suffix[n-1]=nums[n-1];
        for(int i=n-2;i>0;i--)
        {
            suffix[i]=min(suffix[i+1],nums[i]);
        }
        int curr=nums[0];
        for(int j=1;j<n-1;j++)
        {
            if(curr<nums[j]&&nums[j]>suffix[j+1])
            {
                ans=min(ans,curr+nums[j]+suffix[j+1]);
            }
            curr=min(curr,nums[j]);
        }
        return ans==1e9?-1:ans;
    }
};
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int max_value=*max_element(nums.begin(),nums.end());
        long long ans=0;
        int n=nums.size();
        int count=0;
        for(int i=0,j=0;i<n;i++)
        {
            count+=(max_value==nums[i]);
            while(count>=k)
            {
                count-=(max_value==nums[j]);
                j++;
            }
            ans+=i-j+1;
        }
        return 1ll*n*(n+1)/2-ans;
    }
};
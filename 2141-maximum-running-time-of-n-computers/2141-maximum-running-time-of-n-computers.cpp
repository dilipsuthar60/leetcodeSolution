class Solution {
public:
    bool find(vector<int>&nums,long long computer,long long mid)
    {
        long long total_time=computer*mid;
        long long sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=min(nums[i]*1ll,mid);
        }
        return sum>=total_time;
    }
    long long maxRunTime(int N, vector<int>&nums) 
    {
        long long ans=0;
        int n=nums.size();
        long long l=1;
        long long r=1e14;
        while(l<=r)
        {
            long long mid=(l+r)/2;
            if(find(nums,N,mid))
            {
                ans=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return ans;
    }
};
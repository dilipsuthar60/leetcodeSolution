class Solution {
public:
    int mod=1e9+7;
    int find(vector<long long>&nums)
    {
        int n=nums.size();
        long long right=accumulate(nums.begin(),nums.end(),0ll);
        long long cost=0;
        for(int i=0;i<n;i++)
        {
            right-=nums[i];
            cost+=right-nums[i]*(n-i-1);
            cost%=mod;
        }
        return cost%mod;
    }
    int sumDistance(vector<int>& arr, string s, int d) 
    {
        int n=arr.size();
        vector<long long>nums(n,0);
        for(int i=0;i<n;i++)
        {
            if(s[i]=='L')
            {
                nums[i]=arr[i]-d;
            }
            else
            {
                nums[i]=arr[i]+d;
            }
        }
        sort(nums.begin(),nums.end());
        return find(nums);
    }
};
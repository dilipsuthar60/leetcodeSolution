class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());
        long long sum=0;
        int len=0;
        int j=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            sum=sum+nums[i];
            while(k<((1ll*nums[i]*(i-j+1))-sum))
            {
                sum=sum-nums[j++];
            }
            len=max(len,i-j+1);
        }
        return len;
    }
};
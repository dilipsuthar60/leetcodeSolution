class Solution {
public:
    vector<int> decrypt(vector<int>& nums, int k) 
    {
        int n=nums.size();
        vector<int>dp(n,0);
        if(k==0)
        {
            return dp;
        }
        int s=1,e=k;
        if(k<0)
        {
            k*=-1;
            s=n-k;
            e=n-1;
        }
        int sum=0;
        for(int i=s;i<=e;i++)
        {
            sum+=nums[i];
        }
        for(int i=0;i<n;i++)
        {
            dp[i]=sum;
            sum=sum-nums[s%n];
            s++; e++;
            sum=sum+nums[e%n];
        }
        return dp;
    }
};
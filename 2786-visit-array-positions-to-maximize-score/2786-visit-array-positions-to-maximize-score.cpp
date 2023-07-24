class Solution {
public:
    int n;
    vector<vector<long long>>dp;
    long long find(vector<int>&nums,int index,int prev,int x)
    {
        if(index>=n)
        {
            return 0ll;
        }
        if(dp[index][prev]!=-1)
        {
            return dp[index][prev];
        }
        long long take,notTake;
        take=notTake=-1e18;
        if(nums[index]&1)
        {
            if(prev)
            {
                take=max(take,nums[index]+find(nums,index+1,1,x));
            }
            else
            {
                take=max(take,nums[index]-x+find(nums,index+1,1,x));
            }
        }
        else
        {
            if(prev)
            {
                take=max(take,nums[index]-x+find(nums,index+1,0,x));
            }
            else
            {
                take=max(take,nums[index]+find(nums,index+1,0,x));
            }
        }
        notTake=max(notTake,find(nums,index+1,prev,x));
        return dp[index][prev]= max(take,notTake);
    }
    long long maxScore(vector<int>& nums, int x) 
    {
        n=nums.size();
        dp=vector<vector<long long>>(n+1,vector<long long>(2,-1));
        int prev=nums[0]%2;
        return nums[0]+find(nums,1,prev,x);
    }
};
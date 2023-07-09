class Solution {
public:
    int n;
    int dp[501];
    int find(vector<int>&nums,int index,int k)
    {
        if(index>=n)
        {
            return 0;
        }
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        int ans=0;
        int curr_max=0;
        for(int i=index;i<min(n,index+k);i++)
        {
            curr_max=max(curr_max,nums[i]);
            ans=max(ans,curr_max*(i-index+1)+find(nums,i+1,k));
        }
        return dp[index]= ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n=arr.size();
        memset(dp,-1,sizeof(dp));
        return find(arr,0,k);
    }
};
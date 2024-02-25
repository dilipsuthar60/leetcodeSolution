class Solution {
public:
    int n;
    int dp[2005][2005];
    int find(vector<int>&nums,int sum,int i,int j)
    {
        if(i>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        if(nums[i]+nums[i+1]==sum)
        {
            ans=max(ans,1+find(nums,sum,i+2,j));
        }
        if(nums[i]+nums[j]==sum)
        {
            ans=max(ans,1+find(nums,sum,i+1,j-1));
        }
        if(nums[j]+nums[j-1]==sum)
        {
            ans=max(ans,1+find(nums,sum,i,j-2));
        }
        return dp[i][j] = ans;
    }
    int maxOperations(vector<int>& nums) {
        n=nums.size();
        memset(dp,-1,sizeof(dp));
        int firstOperation=find(nums,nums[0]+nums[1],2,n-1);
        int secondOperation=find(nums,nums[n-1]+nums[n-2],0,n-3);
        int thirdOperation=find(nums,nums[0]+nums[n-1],1,n-2);
        return 1+max({firstOperation,secondOperation,thirdOperation});
    }
};
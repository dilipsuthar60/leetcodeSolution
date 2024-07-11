class Solution {
public:
    int dp[40000][3];
    int find(vector<int>&nums,int index,int buy)
    {
        if(index>=nums.size())
        {
            return 0;
        }
        if(dp[index][buy]!=-1)
        {
            return dp[index][buy];
        } 
        int profit=0;
        if(buy)
        {
            profit=max(-nums[index]+find(nums,index+1,0),find(nums,index+1,1));
        }
        else
        {
            profit=max(nums[index]+find(nums,index+1,1),find(nums,index+1,0));
        }
        return dp[index][buy]=profit;
    }
    int maxProfit(vector<int>& nums) 
    {
        memset(dp,-1,sizeof(dp));
        return find(nums,0,1);
    }
};
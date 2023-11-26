class Solution {
public:
    int dp[1001][1001];
    int find(vector<int>&nums,int index,int limit)
    {
        if(index>=nums.size())
        {
            return 0;
        }
        if(dp[index][limit]!=-1)
        {
            return dp[index][limit];
        }
        int op1=nums[index]+find(nums,index+1,index+1);
        int op2=1e8;
        if(limit>0)
        {
            op2=find(nums,index+1,limit-1);
        }
        return dp[index][limit]= min(op1,op2);
    }
    int minimumCoins(vector<int>&nums) 
    {
        memset(dp,-1,sizeof(dp));
        return nums.front()+find(nums,1,1);
    }
};
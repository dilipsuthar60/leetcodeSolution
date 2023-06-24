class Solution {
public:
    int n;
    int dp[21][90005];
    int find(vector<int>&nums,int index,int diff)
    {
        if(index==n)
        {
            return diff==0?0:-1e9;
        }
        if(dp[index][diff+5000]!=-1)
        {
            return dp[index][diff+5000];
        }
        int not_take=find(nums,index+1,diff);
        int take1=nums[index]+find(nums,index+1,diff+nums[index]);
        int take2=find(nums,index+1,diff-nums[index]);
        return dp[index][diff+5000]= max({not_take,take1,take2});
    }
    int tallestBillboard(vector<int>& rods) {
        n=rods.size();
        memset(dp,-1,sizeof(dp));
        int value=find(rods,0,0);
        if(value<0)
        {
            return 0;
        }
        return value;
    }
};
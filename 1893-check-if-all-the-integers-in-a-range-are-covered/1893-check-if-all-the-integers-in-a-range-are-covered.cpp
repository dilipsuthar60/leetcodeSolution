class Solution {
public:
    // int mx=1e8;
    int dp[60];
    bool isCovered(vector<vector<int>>& nums, int left, int right) 
    {
        for(int i=0;i<nums.size();i++)
        {            
            dp[nums[i][0]]++;
            dp[nums[i][1]+1]--;
        }
        for(int i=1;i<52;i++)
        {
            dp[i]+=dp[i-1];
        }
        for(int i=left;i<=right;i++)
        {
            if(dp[i]==0)
            {
                return false;
            }
        }
        return true;
    }
};
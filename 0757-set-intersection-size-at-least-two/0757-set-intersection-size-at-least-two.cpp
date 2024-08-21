class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        if(a[1]==b[1])
        {
            return a[0]<b[0];
        }
        return a[1]<b[1];
    }
    int intersectionSizeTwo(vector<vector<int>>& nums) 
    {
        int n=nums.size();
        sort(nums.begin(),nums.end(),cmp);
        vector<int>dp;
        dp.push_back(nums[0][1]-1);
        dp.push_back(nums[0][1]);
        for(int i=1;i<n;i++)
        {
            if(nums[i][0]>dp.back())
            {
                dp.push_back(nums[i][1]-1);
                dp.push_back(nums[i][1]);
            }
            else if(nums[i][0]==dp.back())
            {
                dp.push_back(nums[i][1]);
            }
            else if(nums[i][0]>dp[dp.size()-2])
            {
                dp.push_back(nums[i][1]);
            }
        }
        return dp.size();
    }
};
class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        return a[1]<b[1];
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) 
    {
        vector<vector<int>>nums;
        for(int i=0;i<profit.size();i++)
        {
            nums.push_back({startTime[i],endTime[i],profit[i]});
        }
        int n=profit.size();
        sort(nums.begin(),nums.end(),cmp);
        vector<int>dp(n,INT_MIN);
        dp[0]=nums[0][2];
        for(int i=1;i<n;i++)
        {
            int l=0;
            int r=i-1;
            int cost=nums[i][2];
            int index=-1;
            while(l<=r)
            {
                int mid=(l+r)/2;
                if(nums[mid][1]<=nums[i][0])
                {
                    index=mid;
                    l=mid+1;
                }
                else
                {
                    r=mid-1;
                }
            }
            if(index!=-1)
            {
              cost+=dp[index];   
            }
            dp[i]=max(dp[i-1],cost);
        }
        return dp[n-1];
    }
};
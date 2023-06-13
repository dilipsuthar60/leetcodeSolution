class Solution {
public:
    long long maxStrength(vector<int>& nums) 
    {
        long long cost=-1e18;
        int n=nums.size();
        for(int i=1;i<(1<<n);i++)
        {
            long long curr_cost=-1e18;
            for(int j=0;j<n;j++)
            {
                if(i&(1<<j))
                {
                    if(curr_cost==-1e18)
                    {
                        curr_cost=nums[j];
                    }
                    else
                    {
                        curr_cost*=nums[j];
                    }
                }
            }
            cost=max(cost,curr_cost);
        }
        return cost;
    }
};
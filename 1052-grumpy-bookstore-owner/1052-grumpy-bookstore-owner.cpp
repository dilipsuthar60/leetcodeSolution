class Solution {
public:
    int maxSatisfied(vector<int>& nums, vector<int>& grumpy, int minutes) 
    {
        int n=nums.size();
        int first=0;
        for(int i=0;i<n;i++)
        {
            first+=(nums[i]*(grumpy[i]==0?1:0));
        }
        int second=0;
        int max_second=0;
        for(int i=0;i<n;i++)
        {
            second+=(nums[i]*grumpy[i]);
            if(i>=minutes)
            {
                second-=(nums[i-minutes]*grumpy[i-minutes]);
            }
            max_second=max(max_second,second);
        }
        return first+max_second;
    }
};
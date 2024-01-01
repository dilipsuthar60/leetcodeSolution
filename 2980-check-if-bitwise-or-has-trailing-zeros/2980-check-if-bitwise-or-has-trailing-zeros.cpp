class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int bit[32]={0};
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<32;j++)
            {
                if((1<<j)&nums[i])
                {
                    bit[j]++;
                }
            }
        }
        for(int i=0;i<32;i++)
        {
            if(bit[i]<=n-2)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
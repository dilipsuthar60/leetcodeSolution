class Solution 
{
public:
    vector<int> getMaximumXor(vector<int>& nums, int Bit) 
    {  
        int val=0;
        int n=nums.size();
        int t=pow(2,Bit)-1;
        for(int i=0;i<n;i++)
        {
            val^=nums[i];
        }
        vector<int>v(n,0);
        for(int i=0;i<n;i++)
        {
            v[i]=val^t;
            val^=nums[n-i-1];
        }
        return v;
    }
};
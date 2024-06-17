class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) 
    {
        int n=nums.size();
        vector<long long>rightMax(n,0);
        rightMax[n-1]=nums.back();
        for(int i=n-2;i>=0;i--)
        {
            rightMax[i]=max(rightMax[i+1],1ll*nums[i]);
        }
        long long currentMax=nums.front();
        long long ans=0;
        for(int i=1;i<n-1;i++)
        {
            ans=max(ans,(currentMax-nums[i])*rightMax[i+1]);
            currentMax=max(currentMax,1ll*nums[i]);
        }
        return ans;
    }
};
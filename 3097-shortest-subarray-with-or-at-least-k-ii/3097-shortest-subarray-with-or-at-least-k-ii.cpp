class Solution {
public:
    int getOr(vector<int>&bit)
    {
        int result=0;
        for(int i=0;i<32;i++)
        {
            if(bit[i]) result+=(1<<i);
        }
        return result;
    }
    void update(vector<int>&bit,int element,int value)
    {
        for(int i=0;i<31;i++)
        {
            if(element&(1<<i))
            {
                bit[i]+=value;
            }
        }
    }
    int minimumSubarrayLength(vector<int>& nums, int k) 
    {
        int j=0;
        int n=nums.size();
        vector<int>bit(32,0);
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            update(bit,nums[i],1);
            while(j<=i&&getOr(bit)>=k)
            {
                ans=min(ans,i-j+1);
                update(bit,nums[j++],-1);
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};
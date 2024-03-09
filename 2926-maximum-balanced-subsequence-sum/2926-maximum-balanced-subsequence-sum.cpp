class Solution {
public:
    const int N=1e5+10;
    long long bit[100000+11];
    void update(int i,long long value)
    {
        while(i<N)
        {
            bit[i]=max(bit[i],value);
            i+=(i&-i);
        }
    }
    long long find(int i)
    {
        long long maxSum=0;
        while(i>0)
        {
            maxSum=max(maxSum,bit[i]);
            i-=(i&-i);
        }
        return maxSum;
    }
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            mp[nums[i]-i]=0;
        }
        int index=1;
        for(auto &[key,value]:mp)
        {
            value=index++;
        }
        long long result=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int index=mp[nums[i]-i];
            long long currentMaxSum =1ll*nums[i]+find(index);
            result=max(currentMaxSum,result);
            update(index,currentMaxSum);
        }
        return result;
    }
};
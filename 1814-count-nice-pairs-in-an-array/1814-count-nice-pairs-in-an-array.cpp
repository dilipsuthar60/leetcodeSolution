class Solution {
public:
    int find(int n)
    {
        int sum=0;
        while(n>0)
        {
            sum=sum*10+n%10;
            n=n/10;
        }
        return sum;
    }
    int countNicePairs(vector<int>& nums) 
    {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            int val=find(nums[i]);
            mp[nums[i]-val]++;
        }
        long long  ans=0;
        const int m=1e9+7;
        for(auto &it:mp)
        {
                long long n=it.second;
                ans=ans+((n%m)*((n-1)%m)/2)%m;
        }
        return ans%m;
    }
};
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) 
    {
        map<int,int>mp;
        for(auto it:nums)
        {
            mp[it-k]++;
            mp[it+k+1]--;
        }
        int sum=0;
        int max_range=0;
        for(auto &[a,b]:mp)
        {
            sum+=b;
            b=sum;
            max_range=max(max_range,b);
        }
        return max_range;
    }
};
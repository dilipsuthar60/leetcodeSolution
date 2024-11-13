class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& nums) 
    {
        long long count=0;
        unordered_map<double,int>mp;
        for(auto it:nums)
        {
            double val=double(it[0]*1.0/it[1]);
            count+=mp[val];
            mp[val]++;
        }
        return count;
    }
};
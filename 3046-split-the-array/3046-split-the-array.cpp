class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) 
    {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(auto&item:nums)
        {
            if(++mp[item]>=3)
            {
                return false;
            }
        }
        return true;
    }
};
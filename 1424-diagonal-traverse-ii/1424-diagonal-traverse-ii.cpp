class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums)
    {
        if(nums.size()==0)
        {
            return {};
        }
        map<int,vector<int>>mp;
        int n=nums.size();
        int m=nums[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<nums[i].size();j++)
            {
                mp[i+j].push_back(nums[i][j]);
            }
        }
        vector<int>v;
        for(auto it:mp)
        {
            for(int i=it.second.size()-1;i>=0;i--)
            {
                v.push_back(it.second[i]);
            }
        }
        return v;
    }
};
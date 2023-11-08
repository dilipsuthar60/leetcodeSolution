class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int index, int value)
    {
        int n=nums.size();
        set<pair<int,int>>s;
        for(int i=index;i<n;i++)
        {
            s.insert({nums[i-index],i-index});
            auto  minValue=*s.begin();
            auto  maxValue=*s.rbegin();
            if(abs(i-minValue.second)>=index&&abs(nums[i]-minValue.first)>=value)
            {
                return {i,minValue.second};
            }
            if(abs(i-maxValue.second)>=index&&abs(nums[i]-maxValue.first)>=value)
            {
                return {i,maxValue.second};
            }
        }
        return {-1,-1};
            
    }
};
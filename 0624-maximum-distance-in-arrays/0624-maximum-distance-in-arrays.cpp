class Solution {
public:
    int maxDistance(vector<vector<int>>& nums) 
    {
        int maximum=nums[0].back();
        int minimum=nums[0].front();
        int ans=-1e9;
        for(int i=1;i<nums.size();i++){
            int currentMaximum=nums[i].back();
            int currentMinimum=nums[i].front();
            ans=max({ans,abs(maximum-currentMinimum),abs(minimum-currentMaximum)});
            maximum=max(currentMaximum,maximum);
            minimum=min(currentMinimum,minimum);
        }
        return ans;
    }
};
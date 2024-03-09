class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        for(auto &num:nums1)
        {
            mp[num]++;
        }
        int ans=INT_MAX;
        for(auto &num:nums2)
        {
            if(mp.find(num)!=mp.end())
            {
                ans=min(ans,num);
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};
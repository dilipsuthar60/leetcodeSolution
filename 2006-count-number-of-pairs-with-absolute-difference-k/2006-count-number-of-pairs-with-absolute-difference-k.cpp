class Solution {
public:
    int countKDifference(vector<int>& nums, int k) 
    {
        int n=nums.size();
        int count=0;
        unordered_map<int,int>mp;
        for(auto &num:nums){
            count+=mp[num+k]+mp[num-k];
            mp[num]++;
        }
        return count;
    }
};
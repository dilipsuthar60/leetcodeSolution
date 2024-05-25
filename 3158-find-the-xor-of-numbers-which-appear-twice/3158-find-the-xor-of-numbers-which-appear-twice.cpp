class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto &item:nums){
            mp[item]++;
        }
        int ans=0;
        for(auto &[key,value]:mp)
        {
            if(value==2)
            {
                ans^=key;
            }
        }
        return ans;
    }
};
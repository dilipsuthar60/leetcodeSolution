class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_map<string,int>mp;
        for(int i=0,n=nums.size();i<n;i++){
            string s=to_string(nums[i]);
            mp[s]++;
            while(s.size()&&s.back()=='0') s.pop_back();
            reverse(s.begin(),s.end());
            mp[s]++;
        }
        return mp.size();
    }
};
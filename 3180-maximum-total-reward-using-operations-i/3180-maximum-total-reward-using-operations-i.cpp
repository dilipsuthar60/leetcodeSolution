class Solution {
public:
    int maxTotalReward(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        set<int>s;
        for(int i=0;i<n;i++)
        {
            for(auto &it:s){
                if(it>=nums[i]) break;
                s.insert(nums[i]+it);
            }
            s.insert(nums[i]);
        }
        return *s.rbegin();
    }
};
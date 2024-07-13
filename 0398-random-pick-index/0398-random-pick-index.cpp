class Solution {
public:
    unordered_map<int,vector<int>>mp;
    Solution(vector<int>& nums) {
        for(int i=0,n=nums.size();i<n;i++){
            mp[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        int size=mp[target].size();
        int index=rand()%size;
        return mp[target][index];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
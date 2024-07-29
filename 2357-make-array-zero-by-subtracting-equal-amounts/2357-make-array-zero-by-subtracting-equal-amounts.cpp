class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        set<int>s;
        for(auto &item:nums) if(item>0) s.insert(item);
        return s.size();
    }
};
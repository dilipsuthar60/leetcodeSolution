class Solution {
public:
    int subarrayBitwiseORs(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>prev;
        unordered_set<int>distict;
        for(int i=0;i<n;i++){
            unordered_set<int>current;
            for(auto it:prev){
                current.insert(nums[i]|it);
            }
            current.insert(nums[i]);
            for(auto &it:current){
                distict.insert(it);
            }
            prev=current;
        }
        return distict.size();
    }
};
class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        int n=nums.size();
        unordered_map<int,vector<int>>mp;
        int index=0;
        for(auto &it:nums) mp[it].push_back(index++);
        vector<int>ans;
        for(auto &query:queries){
            if(mp[x].size()<query){
                ans.push_back(-1);
            }
            else{
                ans.push_back(mp[x][query-1]);
            }
        }
        return ans;
    }
};
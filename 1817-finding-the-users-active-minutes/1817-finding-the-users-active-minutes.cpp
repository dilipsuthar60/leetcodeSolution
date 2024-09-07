class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int>result(k,0);
        unordered_map<int,unordered_set<int>>mp;
        for(auto &log:logs){
            mp[log[0]].insert(log[1]);
        }
        for(auto &[key,value]:mp){
            result[value.size()-1]++;
        }
        return result;
    }
};
class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        int n = s.size();
        unordered_map<string, int> mp;
        int size = n / k;
        for (int i = 0; i < n; i += size) mp[s.substr(i, size)]++;
        for (int i = 0; i < n; i += size) mp[t.substr(i, size)]--;
        
        for (auto &[key,value] : mp) if (value != 0) return false;
        
        return true;
    }
};
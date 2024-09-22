class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& banned) {
        unordered_set<string>s;
        for(auto&it:banned){
            s.insert(it);
        }
        int count=0;
        for(auto &it:message){
            if(s.find(it)!=s.end()){
                count++;
            }
        }
        return count>=2;
    }
};
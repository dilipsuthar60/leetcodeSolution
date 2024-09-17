class Solution {
public:
    int getHashValue(string &s){
        return stoi(s.substr(0,2))*60+stoi(s.substr(3));
    }
    vector<string> alertNames(vector<string>& name, vector<string>&time) {
        unordered_map<string,vector<int>>mp;
        int n=name.size();
        for(int i=0;i<n;i++){
            mp[name[i]].push_back(getHashValue(time[i]));
        }
        vector<string>ans;
        for(auto&[key,value]:mp){
            sort(value.begin(),value.end());
            for(int i=0;i+2<value.size();i++){
                if(abs(value[i]-value[i+2])<=60){
                    ans.push_back(key);
                    break;
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
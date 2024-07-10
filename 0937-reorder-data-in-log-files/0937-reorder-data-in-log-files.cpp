class Solution {
public:
    bool isAlpha(char ch){
        return (ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z');
    }
    vector<string> reorderLogFiles(vector<string>& str) {
        int n=str.size();
        vector<pair<string,string>>letterLogs;
        vector<string>digitLogs;
        for(auto &s:str){
            int i=0;
            while(s[i]!=' ') i++;
            if(isAlpha(s[i+1])){
                letterLogs.push_back({s.substr(0,i),s.substr(i+1)});
            }
            else{
                digitLogs.push_back(s);
            }
        }
        sort(letterLogs.begin(),letterLogs.end(),[&](auto &a,auto&b){
            return a.second==b.second?a.first<b.first:a.second<b.second;
        });
        vector<string>result;
        for(auto &it:letterLogs) result.push_back(it.first+" "+it.second);
        for(auto &it:digitLogs) result.push_back(it);
        return result;
    }
};
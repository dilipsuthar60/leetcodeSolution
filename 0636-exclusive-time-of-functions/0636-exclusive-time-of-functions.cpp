class Solution {
public:
    vector<string>find(string &s){
        stringstream ss(s);
        vector<string>ans;
        string str;
        while(getline(ss,str,':')){
            ans.push_back(str);
        }
        return ans;
    }
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<pair<int,int>>s;
        vector<int>ans(n,0);
        for(auto &it:logs){
            vector<string>v=find(it);
            if(v[1]=="start"){
                s.push({stoi(v[0]),stoi(v[2])});
            }
            else{
                int time = stoi(v[2])-s.top().second+1;
                ans[stoi(v[0])]+=time;
                s.pop();
                if(s.size()){
                    ans[s.top().first]-=time;
                }
            }
        }
        return ans;
    }
};
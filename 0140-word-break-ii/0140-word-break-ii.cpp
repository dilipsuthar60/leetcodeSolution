class Solution {
public:
    unordered_set<string>st;
    void find(string&s,int index,string curr,vector<string>&result){
        if(index>=s.size()){
            curr.pop_back();
            result.push_back(curr);
            return ;
        }
        for(int i=index;i<s.size();i++)
        {
            string current=s.substr(index,i-index+1);
            if(st.count(current)){
                find(s,i+1,curr+current+" ",result);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& word) {
        for(auto &it:word){
            st.insert(it);
        }
        vector<string>result;
        find(s,0,"",result);
        return result;
    }
};
class Solution {
public:
    void find(string s,string str,vector<string>&ans,unordered_set<string>&st)
    {
        if(s.size()==0)
        {
            str.pop_back();
            ans.push_back(str);
            return ;
        }
        for(int i=0;i<s.size();i++)
        {
            string left=s.substr(0,i+1);
            if(st.count(left))
            {
                string right=s.substr(i+1);
                find(right,str+left+" ",ans,st);
            }
        }
            
    }
    vector<string> wordBreak(string s, vector<string>& word) 
    {
        unordered_set<string>st(word.begin(),word.end());
        vector<string>ans;
        find(s,"",ans,st);
        return ans;
    }
};
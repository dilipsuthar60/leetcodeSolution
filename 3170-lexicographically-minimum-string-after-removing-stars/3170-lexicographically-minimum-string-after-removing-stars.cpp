class Solution {
public:
    string clearStars(string s) {
        int n=s.size();
        vector<bool>visited(n,true);
        set<pair<char,int>>st;
        for(int i=0;i<n;i++){
            if(s[i]=='*'&&st.size()){
                auto [ch,index]=*st.begin();
                st.erase(st.begin());
                visited[-index]=false;
            }
            else{
                st.insert({s[i],-i});
            }
        }
        string result="";
        for(int i=0;i<n;i++)
        {
            if(s[i]!='*'&&visited[i]){
                result+=s[i];
            }
        }
        return result;
    }
};
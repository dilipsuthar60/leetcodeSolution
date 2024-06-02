class Solution {
public:
    string clearStars(string s) {
        int n=s.size();
        unordered_map<int,bool>removeIndex;
        set<pair<char,int>>st;
        for(int i=0;i<n;i++){
            if(s[i]=='*'&&st.size()){
                auto [ch,index]=*st.begin();
                st.erase(st.begin());
                removeIndex[abs(index)]=true;
            }
            else{
                st.insert({s[i],-i});
            }
        }
        string result="";
        for(int i=0;i<n;i++)
        {
            if(s[i]!='*'&&removeIndex.find(i)==removeIndex.end()){
                result+=s[i];
            }
        }
        return result;
    }
};
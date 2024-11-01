class Solution {
public:
    string makeFancyString(string s) {
//         string ans="";
//         for(auto &it:s){
//             if(ans.size()>=2&&ans.back()==it&&ans[ans.size()-2]==it){
//                 ans.pop_back();
//             }
//             ans+=it;
//         }
//         return ans;
        
        
        
        if(s.size()<3) return s;
        int j=2;
        for(int i=2;i<s.size();i++){
            if(s[i]!=s[j-1]||s[i]!=s[j-2]){
                s[j++]=s[i];
            }
        }
        return s.substr(0,j);
    }
};
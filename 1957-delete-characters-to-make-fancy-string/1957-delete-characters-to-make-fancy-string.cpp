class Solution {
public:
    string makeFancyString(string s) {
        string ans="";
        for(auto &it:s){
            if(ans.size()>=2&&ans.back()==it&&ans[ans.size()-2]==it){
                ans.pop_back();
            }
            ans+=it;
        }
        return ans;
    }
};
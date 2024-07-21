class Solution {
public:
    bool doesAliceWin(string s) {
        string v="aeiou";
        for(int i=0,n=s.size();i<n;i++){
            if(v.find(s[i])!=string::npos) return true;
        }
        return false;
    }
};
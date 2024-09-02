class Solution {
public:
    string clearDigits(string s) {
        string result="";
        for(int i=0;i<s.size();i++){
            if(result.size()&&s[i]>='0'&&s[i]<='9'){
                result.pop_back();
            }
            else{
                result.push_back(s[i]);
            }
        }
        return result;
    }
};
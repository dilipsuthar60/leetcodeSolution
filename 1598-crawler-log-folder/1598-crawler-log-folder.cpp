class Solution {
public:
    int minOperations(vector<string>& s) {
        stack<string>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=="../"){
                if(st.size())st.pop();
            }
            else if(s[i]=="./") continue;
            else{
                st.push(s[i]);
            }
        }
        return st.size();
    }
};
class Solution {
public:
    string decodeString(string s) {
        int n=s.size();
        stack<string>st;
        string currentString="";
        string currentDigit="";
        for(int i=0;i<n;i++){
            if(s[i]=='['){
                st.push(currentString);
                st.push(currentDigit);
                currentString=currentDigit="";
            }
            else if(s[i]==']'){
                int num=stoi(st.top());
                st.pop();
                string prevString=st.top();
                st.pop();
                string curr=currentString;
                currentString=prevString;
                for(int i=0;i<num;i++){
                    currentString+=curr;
                }
            }
            else if(isdigit(s[i])){
                currentDigit+=s[i];
            }
            else{
                currentString+=s[i];
            }
        }
        return currentString;
    }
};
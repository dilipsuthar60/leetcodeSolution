class Solution {
public:
    string decodeAtIndex(string s, int k) {
        int n=s.size();
        long long curr=0;
        vector<int>v;
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){
                curr=curr*(s[i]-'0');
            }
            else{
                curr++;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(isdigit(s[i])){
                curr/=(s[i]-'0');
                k%=curr;
            }
            else{
                if(k==0||k==curr){
                    return string(1,s[i]);
                }
                curr--;
            }
        }
        return "";
    }
};
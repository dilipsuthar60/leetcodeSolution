class Solution {
public:
    int maxOperations(string s) {
        int n=s.size();
        int one=0;
        int result=0;
        for(int i=0;i<n;i++){
            one+=(s[i]-'0');
            if(i&&s[i]=='0'&&s[i-1]=='1'){
                result+=one;
            }
        }
        return result;
    }
};
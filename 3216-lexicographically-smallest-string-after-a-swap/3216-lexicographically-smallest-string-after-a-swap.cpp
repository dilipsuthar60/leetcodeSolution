class Solution {
public:
    string getSmallestString(string s) {
        int n=s.size();
        for(int i=0;i<n-1;i++){
            int a=s[i]-'0';
            int b=s[i+1]-'0';
            if(a>b&&(a%2==b%2)){
                swap(s[i],s[i+1]);
                break;
            }
        }
        return s;
    }
};
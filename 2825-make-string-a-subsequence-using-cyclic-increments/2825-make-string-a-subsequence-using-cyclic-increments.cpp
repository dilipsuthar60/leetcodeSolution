class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        int i=0,j=0;
        for(;i<n&&j<m;i++){
            if(str1[i]==str2[j]||(str1[i]+1==str2[j])||(str1[i]-25==str2[j])){
                j++;
            }
        }
        return j==str2.size();
    }
};
class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int result=0;
        int count[2]={0};
        for(int i=0,n=s.size(),j=0;i<n;i++){
            count[s[i]-'0']++;
            while(count[0]>k&&count[1]>k){
                count[s[j++]-'0']--;
            }
            result+=(i-j+1);
        }
        return result;
    }
};
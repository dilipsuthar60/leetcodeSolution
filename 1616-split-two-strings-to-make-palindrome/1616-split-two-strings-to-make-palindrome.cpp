class Solution {
public:
    bool isPalindrome(const string &s, int i,int j){
        for(;i<j;i++,j--){
            if(s[i]!=s[j]) return false;
        }
        return true;
    }
    int find(const string &s1, const string &s2){
        int i=0;
        int j=s1.size()-1;
        while(i<j&&s1[i]==s2[j]){
            i++;
            j--;
        }
        return isPalindrome(s1,i,j)||isPalindrome(s2,i,j);
    }
    bool checkPalindromeFormation(string s1, string s2) {
        return find(s1,s2)||find(s2,s1);
    }
};
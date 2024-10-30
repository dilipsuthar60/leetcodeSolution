class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long count=0;
        for(int i=0;i<s.size();i++) 
        {
            count+=(s[i]==c); 
        }  
        return count*(count+1)/2;
    }
};
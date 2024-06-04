class Solution {
public:
    int minChanges(string s) {
        int count=0;
        int n=s.size();
        for(int i=1;i<n;i+=2)
        {
            count+=(s[i]!=s[i-1]);
        }
        return count;
    }
};
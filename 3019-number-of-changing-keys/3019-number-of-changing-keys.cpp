class Solution {
public:
    char getLower(char ch)
    {
        return ch>='a'&&ch<='z'?ch:char(ch-'A'+97);
    }
    int countKeyChanges(string s) {
        int n=s.size();
        int count=0;
        for(int i=0;i<s.size()-1;i++)
        {
            count+=(getLower(s[i])==getLower(s[i+1]))?0:1;
        }
        return count;
    }
};
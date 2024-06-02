class Solution {
public:
    int minimumChairs(string s) {
        int chair=0;
        int count=0;
        for(int i=0;i<s.size();i++)
        {
            count+=(s[i]=='E')?1:-1;
            chair=max(count,chair);
        }
        return chair;
    }
};
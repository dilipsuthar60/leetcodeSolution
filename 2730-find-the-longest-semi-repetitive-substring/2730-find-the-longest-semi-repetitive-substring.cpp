class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) 
    {
        int max_len=0;
        int count=0;
        for(int i=0,n=s.size(),j=0;i<n;i++)
        {
            if(i&&s[i]==s[i-1])
            {
                count++;
            }
            while(count>1)
            {
                if(j+1<n)
                count-=(s[j]==s[j+1]);
                j++;
            }
            max_len=max(max_len,i-j+1);
        }
        return max_len;
    }
};
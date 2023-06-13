class Solution {
public:
    string smallestString(string s) 
    {
        int n=s.size();
        int yes=1;
        int index=0;
        while(index<n&&s[index]=='a')
        {
            index++;
        }
        if(index==n)
        {
            s[index-1]='z';
            return s;
        }
        for(int i=index;i<n;i++)
        {
            if(s[i]!='a')
            {
                s[i]--;
            }
            else
            {
                break;
            }
        }
        return s;
    }
};
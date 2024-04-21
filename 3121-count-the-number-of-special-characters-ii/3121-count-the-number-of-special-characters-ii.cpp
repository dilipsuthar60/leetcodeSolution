class Solution {
public:
    bool isUpper(char ch)
    {
        return ch>='A'&&ch<='Z';
    }
    int numberOfSpecialChars(string word) 
    {
        int firstCapital[26];
        int lastSmall[26];
        memset(firstCapital,-1,sizeof(firstCapital));
        memset(lastSmall,-1,sizeof(lastSmall));
        int index=0;
        for(auto &ch:word)
        {
            if(isUpper(ch))
            {
                if(firstCapital[ch-'A']==-1)
                {
                    firstCapital[ch-'A']=index;
                }
            }
            else
            {
                lastSmall[ch-'a']=index;
            }
            ++index;
        }
        int count=0;
        for(int i=0;i<26;i++)
        {
            if(lastSmall[i]!=-1&&firstCapital[i]!=-1&&lastSmall[i]<firstCapital[i]) 
            {
                count++;
            }
        }
        return count;
    }
};
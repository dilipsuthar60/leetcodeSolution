class Solution {
public:
    string minWindow(string s, string t) 
    {
        vector<int>dp1(256,0),dp2(256,0);
        for(int i=0;i<t.size();i++)
        {
            dp1[t[i]]++;
        }
        int start=0;
        int count=0;
        int j=0;
        int len=INT_MAX;
        int f=0;
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            dp2[s[i]]++;
            if(dp1[s[i]]!=0&&dp2[s[i]]<=dp1[s[i]])
            {
                count++;
            }
            if(count==t.size())
            {
                while(dp1[s[j]]==0||dp2[s[j]]>dp1[s[j]])
                {
                    dp2[s[j]]--;
                    j++;
                }
                int window=i-j+1;
                if(window<len)
                {
                    f=1;
                    len=window;
                    start=j;
                    // ans=s.substr(j,len);
                }
            }
        }
        if(f)
        {
            return s.substr(start,len);
        }
        return "";
    }
};
class Solution {
public:
    string reverseParentheses(string s) 
    {
        int n=s.size();
        vector<int>backet,pair(n,0);
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                backet.push_back(i);
            }
           if(s[i]==')')
           {
               int val=backet.back();
               backet.pop_back();
               pair[i]=val;
               pair[val]=i;
           }
        }
        string ans="";
        for(int i=0,d=1;i<n;i+=d)
        {
            if(s[i]==')'||s[i]=='(')
            {
                d=-d;
                i=pair[i];
            }
            else
            {
                ans+=s[i];
            }
        }
        return ans;
    }
};
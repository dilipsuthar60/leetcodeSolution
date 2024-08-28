class Solution {
public:
    int longestValidParentheses(string s) 
    {
        int n=s.size();
        vector<int>dp(n+1,-1);
        dp[n]=0;
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                st.push(i);
            }
            else
            {
                if(st.size())
                {
                    int j=st.top();
                    st.pop();
                    int len=i-j+1;
                    if(j&&dp[j-1]!=-1)
                    {
                        len+=dp[j-1];
                    }
                    dp[i]=len;
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
        
    }
};
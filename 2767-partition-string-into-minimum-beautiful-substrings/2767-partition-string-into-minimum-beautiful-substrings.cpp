class Solution {
public:
    int dp[20];
    bool power(string &s,int start,int end)
    {
        int sum=0;
        for(int i=start;i<=end;i++)
        {
            sum=sum<<1|(s[i]-'0');
        }
        
        return 15625 %sum==0;
    }
    int find(string &s,int index)
    {
        if(index>=s.size())
        {
            return 0;
        }
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        if(s[index]=='0')
        {
            return 1e9;
        }
        int ans=1e9;
        for(int i=index;i<s.size();i++)
        {
            if(power(s,index,i))
            {
                ans=min(ans,1+find(s,i+1));
            }
        }
        return dp[index]= ans;
    }
    int minimumBeautifulSubstrings(string s) 
    {
        memset(dp,-1,sizeof(dp));
        int value=find(s,0);
        if(value>=1e9)
        {
            return -1;
        }
        return value;
    }
};
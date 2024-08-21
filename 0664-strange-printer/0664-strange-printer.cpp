class Solution {
public:
    int dp[101][101];
    int find(string&s,int l,int r)
    {
        if(l>r)
        {
            return 0;
        }
        // int ol=l;
        if(dp[l][r]!=-1){
            return dp[l][r];
        }
        while(l+1<=r&&s[l]==s[l+1])
        {
            l++;
        }
        int ans=1+find(s,l+1,r);
        for(int m=l+1;m<=r;m++)
        {
            if(s[l]==s[m])
            ans=min(ans,find(s,m,r)+find(s,l+1,m-1));
        }
        return dp[l][r] = ans;
    }
    int strangePrinter(string s) 
    {
        memset(dp,-1,sizeof(dp));
        return find(s,0,s.size()-1);
    }
};
class Solution {
public:
    bool isFascinating(int n) {
        string s1=to_string(n);
        string s2=to_string(2*n);
        string s3=to_string(3*n);
        string s=s1+s2+s3;
        vector<int>dp(10,0);
        for(int i=0;i<s.size();i++)
        {
            dp[s[i]-'0']++;
        }
        if(dp[0])
        {
            return false;
        }
        for(int i=1;i<=9;i++)
        {
            if(dp[i]==0)
            {
                return false;
            }
            if(dp[i]>=2)
            {
                return false;
            }
        }
        return true;
    }
};
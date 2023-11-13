class Solution {
public:
    string sortVowels(string s) {
        string vowel="aeiouAEIOU";
        int dp[256]={0};
        for(auto it:s)
        {
            if(vowel.find(it)!=string::npos)
            {
                dp[it]++;
            }
        }
        for(int i=0;i<s.size();i++)
        {
            if(vowel.find(s[i])!=string::npos)
            {
                for(int j=0;j<256;j++)
                {
                    if(dp[j])
                    {
                        s[i]=char(j);
                        dp[j]--;
                        break;
                    }
                }
            }
        }
        return s;
    }
};
class Solution {
public:
    bool check(int dp[]){
        int first=0;
        for(int i=0;i<26;i++){
            if(dp[i]==0) continue;
            if(first==0) first=dp[i];
            else if(first!=dp[i]) return false;
        }
        return true;
    }
    bool equalFrequency(string s) 
    {
        int n=s.size();
        int dp[26]={0};
        for(int i=0;i<n;i++) dp[s[i]-'a']++;
        for(int i=0;i<n;i++){
            dp[s[i]-'a']--;
            if(check(dp)) return true;
            dp[s[i]-'a']++;
        }
        return false;
    }
};
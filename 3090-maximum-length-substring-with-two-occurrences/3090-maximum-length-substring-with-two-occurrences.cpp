class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
        vector<int>dp(26,0);
        int j=0;
        int ans=0;
        for(int i=0;i<n;i++){
            dp[s[i]-'a']++;
            while(j<=i&&dp[s[i]-'a']>2){
                dp[s[j]-'a']--;
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};
class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        vector<int>dp(26,0);
        for(auto &it:s) dp[it-'a']++;
        int count=0;
        for(int i=0;i<26;i++){
            if(dp[i]){
                count+=(dp[i]%2==0?2:1);
            }
        }
        return count;
    }
};
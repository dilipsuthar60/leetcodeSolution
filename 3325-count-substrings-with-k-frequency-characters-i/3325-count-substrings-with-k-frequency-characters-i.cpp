class Solution {
public:
    bool find(vector<int>&dp,int k){
        for(int i=0;i<26;i++){
            if(dp[i]>=k) return true;
        }
        return false;
    }
    int numberOfSubstrings(string s, int k) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            vector<int>dp(26,0);
            for(int j=i;j<n;j++){
                dp[s[j]-'a']++;
                if(find(dp,k)){
                    ans++;
                }
            }
        }
        return ans;
    }
};
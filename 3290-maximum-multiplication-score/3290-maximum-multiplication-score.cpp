class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        vector<long long>dp(5,-1e15);
        dp[0]=0;
        for(int i=0;i<b.size();i++){
            vector<long long>ndp = dp;
            for(int j=0;j<4;j++){
                ndp[j+1]=max(ndp[j+1],dp[j]+1ll*a[j]*b[i]);
            }
            swap(dp,ndp);
        }
        return dp.back();
    }
};
class Solution {
public:
    int dp[101][26];
    int find(string &s,int index,int sum){
        if(index>=s.size()){
            return (sum%25)?-1e9:0;
        }
        if(dp[index][sum]!=-1)  return dp[index][sum];
        int take=1+find(s,index+1,(sum*10+(s[index]-'0'))%25);
        int notTake=find(s,index+1,sum);
        return dp[index][sum] = max(take,notTake);
    }
    int minimumOperations(string num) {
        memset(dp,-1, sizeof(dp));
        return num.size()-find(num,0,0);
    }
};
class Solution {
public:
    int dp[201][201];
    int find(vector<vector<int>>&ss,vector<vector<int>>&ts,int day,int city,int n,int k){
        if(day==k) return 0;
        if(dp[day][city]!=-1) return dp[day][city];
        int ans=ss[day][city]+find(ss,ts,day+1,city,n,k);
        for(int i=0;i<n;i++){
            if(i!=city){
                ans=max(ans,ts[city][i]+find(ss,ts,day+1,i,n,k));
            }
        }
        return dp[day][city]= ans;
    }
    int maxScore(int n, int k, vector<vector<int>>& ss, vector<vector<int>>& ts) {
        int ans=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            ans=max(ans,find(ss,ts,0,i,n,k));
        }
        return ans;
    }
};
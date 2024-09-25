class Solution {
public:
    int dp[1001];
    bool check(vector<int>&nums){
        int maxValue=-1e9;
        int minValue=1e9;
        for(int i=0;i<26;i++){
            if(nums[i]==0) continue;
            maxValue=max(maxValue,nums[i]);
            minValue=min(minValue,nums[i]);
        }
        return minValue==maxValue;
    }
    int find(string &s,int index){
        if(index>=s.size()) return 0;
        if(dp[index]!=-1) return dp[index];
        int ans=1e7;
        vector<int>nums(26,0);
        for(int i=index;i<s.size();i++){
            nums[s[i]-'a']++;
            if(check(nums)){
                ans=min(ans,1+find(s,i+1));
            }
        }
        return dp[index] = ans;
    }
    int minimumSubstringsInPartition(string s) {
        memset(dp,-1,sizeof(dp));
        return find(s,0);
    }
};
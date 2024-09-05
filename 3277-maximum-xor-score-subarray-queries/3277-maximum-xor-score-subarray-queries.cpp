class Solution {
public:
    vector<int> maximumSubarrayXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        for(int gap=0;gap<n;gap++){
            for(int i=0,j=gap;j<n;j++,i++){
                if(gap==0){
                    dp[i][j]=nums[i];
                }
                else if(gap==1){
                    dp[i][j]=nums[i]^nums[j];
                }
                else{
                    dp[i][j]=dp[i+1][j]^dp[i][j-1];
                }
            }
        }
        for(int gap=1;gap<n;gap++){
            for(int i=0,j=gap;j<n;j++,i++){
                if(gap==1){
                    dp[i][j]=max({dp[i][j],nums[i],nums[j]});
                }
                else{
                    dp[i][j]=max({dp[i][j],dp[i+1][j],dp[i][j-1]});
                }
            }
        }
        vector<int>ans;
        for(auto &it:queries){
            ans.push_back(dp[it[0]][it[1]]);
        }
        return ans;
    }
};
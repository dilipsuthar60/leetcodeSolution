class Solution {
public:
    vector<vector<int>>dp;
    int find(int node,vector<int>&nums,int &count,int req,int p=-1){
        int sum=nums[node];
        for(auto &it:dp[node]){
            if(it!=p){
                sum+=find(it,nums,count,req,node);
            }
        }
        if(sum==req){
            count++;
            return 0;
        }
        return sum;
    }
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int n=edges.size();
        dp=vector<vector<int>>(n+1);
        for(auto &it:edges){
            dp[it[0]].push_back(it[1]);
            dp[it[1]].push_back(it[0]);
        }
        int sum=accumulate(nums.begin(),nums.end(),0);
        int ans=0;
        for(int i=1;i*i<=sum;i++){
            if(sum%i==0){
                int count=0;
                find(0,nums,count,sum/i);
                if(count==i){
                    ans=max(ans,i-1);
                }
                count=0;
                find(0,nums,count,i);
                if(count==sum/i){
                    ans=max(ans,sum/i-1);
                }
            }
        }
        return ans;
    }
};
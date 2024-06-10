class Solution {
public:
    int dp[2001][4001];
    int find(vector<int>&nums,int index,int sum=0){
        if(index>=nums.size()) return 0;
        if(dp[index][sum]!=-1) return dp[index][sum];
        int result=find(nums,index+1,sum);
        if(sum<nums[index]){
            result=max(result,nums[index]+find(nums,index+1,sum+nums[index]));
        }
        return dp[index][sum] = result;
    }
    int maxTotalReward(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        set<int>s;
        for(int i=0;i<n;i++)
        {
            for(auto it:s){
                if(it>=nums[i]) break;
                s.insert(nums[i]+it);
            }
            s.insert(nums[i]);
        }
        return *s.rbegin();
    }
};
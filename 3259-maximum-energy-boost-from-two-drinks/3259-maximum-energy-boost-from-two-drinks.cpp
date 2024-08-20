class Solution {
public:
    long long dp[100005][2];
    long long find(vector<int>&nums1,vector<int>&nums2,int index,int type){
        if(index>=nums1.size()) return 0;
        if(dp[index][type]!=-1) return dp[index][type];
        long long currentCost=(type==0)?nums1[index]:nums2[index];
        long long noSwitching=currentCost+find(nums1,nums2,index+1,type);
        long long switching=currentCost+find(nums1,nums2,index+2,1-type);
        return dp[index][type]= max(noSwitching,switching);
    }
    long long maxEnergyBoost(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        return max(find(nums1,nums2,0,0),find(nums1,nums2,0,1));
    }
};
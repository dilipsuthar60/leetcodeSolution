class Solution {
public:
    int dp[100005][3];
    int find(vector<int>&nums1,vector<int>&nums2,int index,int lastType=-1){
        if(index>=nums1.size()) return 0;
        int ans=0;
        if(dp[index][lastType+1]!=-1) return dp[index][lastType+1];
        if(lastType==-1){
            ans=max(ans,1+find(nums1,nums2,index+1,0));
            ans=max(ans,1+find(nums1,nums2,index+1,1));
            ans=max(ans,find(nums1,nums2,index+1,-1));
        }
        else{
            int lastTypeElement=(lastType==0)?nums1[index-1]:nums2[index-1];
            if(lastTypeElement<=nums1[index]){
                ans=max(ans,1+find(nums1,nums2,index+1,0));
            }
            if(lastTypeElement<=nums2[index]){
                ans=max(ans,1+find(nums1,nums2,index+1,1));
            }
        }
        return dp[index][lastType+1] = ans;
    }
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        return find(nums1,nums2,0);
    }
};
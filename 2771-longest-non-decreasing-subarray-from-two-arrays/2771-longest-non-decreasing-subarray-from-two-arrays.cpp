class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<int>dp1(n,1),dp2(n,1);
        int ans=1;
        for(int i=1;i<n;i++){
            if(nums1[i-1]<=nums1[i]){
                dp1[i]=max(dp1[i],dp1[i-1]+1);
            }
            if(nums2[i-1]<=nums1[i]){
                dp1[i]=max(dp1[i],dp2[i-1]+1);
            }
            if(nums1[i-1]<=nums2[i]){
                dp2[i]=max(dp2[i],dp1[i-1]+1);
            }
            if(nums2[i-1]<=nums2[i]){
                dp2[i]=max(dp2[i],dp2[i-1]+1);
            }
            ans=max({ans,dp1[i],dp2[i]});
        }
        return ans;
    }
};
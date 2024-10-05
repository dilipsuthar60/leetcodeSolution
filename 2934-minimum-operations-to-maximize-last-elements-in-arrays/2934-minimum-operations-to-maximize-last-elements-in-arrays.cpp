class Solution {
public:
    int find(vector<int>&nums1,vector<int>&nums2,int index){
        if(index>=nums1.size()) return 0;
        int ans=1e8;
        if(nums1[index]<=nums1.back()&&nums2[index]<=nums2.back()){
            ans=min(ans,find(nums1,nums2,index+1));
            return ans;
        }
        if(nums2[index]<=nums1.back()&&nums1[index]<=nums2.back()){
            ans=min(ans,1+find(nums1,nums2,index+1));
            return ans;
        }
        return ans;
    }
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int notSwapLast=find(nums1,nums2,0);
        swap(nums1.back(),nums2.back());
        int swapLast=1+find(nums1,nums2,0);
        int ans=min(notSwapLast,swapLast);
        return ans>=1e8?-1:ans;
    }
};
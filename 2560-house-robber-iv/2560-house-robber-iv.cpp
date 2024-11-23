class Solution {
public:
    bool find(vector<int>&nums,int mid,int k){
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=mid){
                k--;
                i++;
            }
        }
        return k<=0;
    }
    int minCapability(vector<int>& nums, int k) {
        int l=0;
        int r=1e9;
        int ans=0;
        while(l<=r){
            int mid=(l+r)/2;
            if(find(nums,mid,k)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};
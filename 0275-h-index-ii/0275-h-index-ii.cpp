class Solution {
public:
    int hIndex(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        int ans=0;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]>=(n-mid)){
                ans=n-mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};
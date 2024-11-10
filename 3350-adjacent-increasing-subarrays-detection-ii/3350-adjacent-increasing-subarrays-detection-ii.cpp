class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int>a(n,1),b(n,1);
        for(int i=1;i<n;i++){
            if(nums[i-1]<nums[i]){
                a[i]+=a[i-1];
            }
        }
        int ans=0;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                b[i]+=b[i+1];
            }
            ans=max(ans,min(a[i],b[i+1]));
        }
        return ans;
    }
};
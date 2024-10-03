class Solution {
public:
    int maxWidthRamp(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>right(n,0);
        right[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            right[i]=max(right[i+1],nums[i]);
        }
        int l=0;
        int r=0;
        int ans=0;
        int leftMinimum=1e9;
        while(l<n&&r<n){
            leftMinimum=min(leftMinimum,nums[l]);
            if(leftMinimum<=right[r]){
                ans=max(ans,r-l);
                r++;
            }
            else{
                l++;
            }
        }
        return ans;
    }
};
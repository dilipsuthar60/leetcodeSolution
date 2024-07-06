class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& nums, int k) {
        int missMatch=0;
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n+k-1;i++){
            if(nums[i%n]!=nums[(i+1)%n]) missMatch++;
            else missMatch=1;
            if(missMatch>=k) ans++;
        }
        return ans;
    }
};
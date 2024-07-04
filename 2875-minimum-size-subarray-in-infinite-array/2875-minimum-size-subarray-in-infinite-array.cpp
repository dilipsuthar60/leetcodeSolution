class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        int n=nums.size();
        long long sum=accumulate(nums.begin(),nums.end(),0ll);
        if(target%sum == 0) return n*(target/sum);
        long long need=target%sum;
        long long currentSum=0;
        int ans=1e9;
        for(int i=0,j=0;i<2*n;i++){
            currentSum+=nums[i%n];
            while(currentSum>need){
                currentSum-=nums[j%n];
                j++;
            }
            if(currentSum==need){
                ans=min(ans,i-j+1);
            }
        }
        if(ans==1e9) return -1;
        return ans+n*(target/sum);
    }
};
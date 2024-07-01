class Solution {
public:
    long long maximumSumOfHeights(vector<int>& nums) 
    {
        int n=nums.size();
        long long result=0;
        for(int i=0;i<n;i++){
            long long current=nums[i];
            long long currentCost=current;
            for(int j=i-1;j>=0;j--){
                current=min(current,1ll*nums[j]);
                currentCost+=current;
            }
            current=nums[i];
            for(int j=i+1;j<n;j++){
                current=min(current,1ll*nums[j]);
                currentCost+=current;
            }
            result=max(result,currentCost);
        }
        return result;
    }
};
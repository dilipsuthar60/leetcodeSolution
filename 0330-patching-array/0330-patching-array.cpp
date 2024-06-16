class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int patch=0;
        long long maxReachNumber=0;
        int index=0;
        while(maxReachNumber<n){
            if(index<nums.size()&&nums[index]<=maxReachNumber+1){
                maxReachNumber+=nums[index++];
            }
            else{
                maxReachNumber+=(maxReachNumber+1);
                patch++;
            }
        }
        return patch;
    }
};
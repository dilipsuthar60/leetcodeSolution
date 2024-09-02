class Solution {
public:
    int chalkReplacer(vector<int>& nums, int k) {
        long long sum=accumulate(nums.begin(),nums.end(),0ll);
        sum=k%sum;
        int result=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=sum){
                sum-=nums[i];
            }
            else{
                result=i;
                break;
            }
        }
        return result;
    }
};
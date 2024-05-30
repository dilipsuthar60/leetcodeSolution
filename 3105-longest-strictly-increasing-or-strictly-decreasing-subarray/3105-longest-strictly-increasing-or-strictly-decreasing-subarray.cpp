class Solution {
public:
    int find(vector<int>&nums){
        int count=1;
        int result=1;
        for(int i=1,n=nums.size();i<n;i++)
        {
            if(nums[i-1]<nums[i]){
                count++;
            }
            else{
                count=1;
            }
            result=max(result,count);
        }
        return result;
    }
    int longestMonotonicSubarray(vector<int>& nums) {
        int firstOperation = find(nums);
        reverse(nums.begin(),nums.end());
        int secondOperation =find(nums);
        return max(firstOperation,secondOperation);
    }
};
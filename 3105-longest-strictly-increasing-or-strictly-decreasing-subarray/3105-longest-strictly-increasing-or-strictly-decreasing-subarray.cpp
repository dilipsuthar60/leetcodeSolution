class Solution {
public:
    int find(vector<int>&nums){
        int result=1;
        int size=nums.size();
        for(int i=1,count=1;i<size;i++)
        {
            count=(nums[i-1]<nums[i]?count+1:1);
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
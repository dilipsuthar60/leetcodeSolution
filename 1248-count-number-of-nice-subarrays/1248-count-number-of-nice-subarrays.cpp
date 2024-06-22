class Solution {
public:
    int find(vector<int>&nums,int k){
        int count=0;
        int subarray=0;
        for(int i=0,j=0;i<nums.size();i++){
            count+=(nums[i]%2);
            while(count>k){
                count-=(nums[j]%2);
                j++;
            }
            subarray+=(i-j+1);
        }
        return subarray;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return find(nums,k)-find(nums,k-1);
    }
};
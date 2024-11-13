class Solution {
public:
    long long find(vector<int>&nums,int target){
        int l=0;
        int r=nums.size()-1;
        sort(nums.begin(),nums.end());
        long long countPair=0;
        while(l<r){
            if((nums[l]+nums[r])<=target){
                countPair+=(r-l);
                l++;
            }
            else{
                r--;
            }
        }
        return countPair;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans=0;
        sort(nums.begin(),nums.end());
        return find(nums,upper)-find(nums,lower-1);
    }
};
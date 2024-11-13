class Solution {
public:
    long long find(vector<int>&nums,int limit){
        int n=nums.size();
        long long count=0;
        for(int l=0,r=n-1;l<r;){
            if((nums[l]+nums[r])>limit){
                r--;
            }
            else{
                count+=(r-l);
                l++;
            }
        }
        return count;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans=0;
        sort(nums.begin(),nums.end());
        return find(nums,upper)-find(nums,lower-1);
    }
};
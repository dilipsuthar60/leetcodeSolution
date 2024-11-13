class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        sort(nums.begin(),nums.end());
        int countPair=0;
        while(l<r){
            if((nums[l]+nums[r])<target){
                countPair+=(r-l);
                l++;
            }
            else{
                r--;
            }
        }
        return countPair;
    }
};
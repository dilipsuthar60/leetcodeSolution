class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if(k==1){
            return nums;
        }
        int count=1;
        int n=nums.size();
        vector<int>ans;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1) count++;
            else count=1;
            if(i>=k-1){
                ans.push_back(count>=k?nums[i]:-1);
            }
        }
        return ans;
    }
};
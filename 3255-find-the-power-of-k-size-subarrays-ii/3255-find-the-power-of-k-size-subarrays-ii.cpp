class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();
        int count=1;
        int index=0;
        vector<int>ans(n-k+1,-1);
        for(int i=1;i<k;i++){
            if(nums[i]==nums[i-1]+1){
                count++;
            }
            else{
                count=1;
            }
        }
        if(count>=k) ans[index]=nums[k-1];
        index++;
        for(int i=k;i<n;i++){
            if(nums[i]==nums[i-1]+1){
                count++;
            }
            else{
                count=1;
            }
            if(count>=k) ans[index]=nums[i];
            index++;
        }
        return ans;
    }
};
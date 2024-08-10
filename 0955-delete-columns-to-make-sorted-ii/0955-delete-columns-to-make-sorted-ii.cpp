class Solution {
public:
    bool isValid(vector<string>&nums){
        for(int i=0;i+1<nums.size();i++){
            if(nums[i]>nums[i+1]) return false;
        }
        return true;
    }
    int minDeletionSize(vector<string>& nums) 
    {
        int n=nums.size();
        vector<string>ans(n,"");
        for(int col=0;col<nums[0].size();col++){
            for(int row=0;row<n;row++){
                ans[row]+=nums[row][col];
            }
            if(!isValid(ans)){
               for(int i=0;i<n;i++){
                   ans[i].pop_back();
               } 
            }
        }
        return nums[0].size()-ans[0].size();
    }
};
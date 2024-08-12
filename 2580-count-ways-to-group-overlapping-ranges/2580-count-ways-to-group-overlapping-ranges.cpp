class Solution {
public:
    int countWays(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end());
        int size=1;
        int end=nums[0][1];
        for(int i=1;i<nums.size();i++){
            if(end>=nums[i][0]){
                end=max(end,nums[i][1]);
            }
            else{
                end=max(end,nums[i][1]);
                size++;
            }
        }
        int result=1;
        const int mod=1e9+7;
        for(int i=1;i<=size;i++){
            result=(result*2);
            result%=mod;
        }
        return result;
    }
};
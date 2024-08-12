class Solution {
public:
    int countWays(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        ans.push_back(nums.front());
        for(int i=1;i<nums.size();i++){
            if(ans.back()[1]>=nums[i][0]){
                ans.back()[0]=min(ans.back()[0],nums[i][0]);
                ans.back()[1]=max(ans.back()[1],nums[i][1]);
            }
            else{
                ans.push_back(nums[i]);
            }
        }
        int size=ans.size();
        int result=1;
        const int mod=1e9+7;
        for(int i=1;i<=size;i++){
            result=(result*2);
            result%=mod;
        }
        return result;
    }
};
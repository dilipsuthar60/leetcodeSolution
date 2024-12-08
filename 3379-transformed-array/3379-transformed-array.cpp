class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>result;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                result.push_back(nums[i]);
            }
            else{
                int index=(i+nums[i]%n+n)%n;
                result.push_back(nums[index]);
            }
        }
        return result;
    }
};
class Solution {
public:
    vector<int> finalPrices(vector<int>& nums) {
        int n=nums.size();
        vector<int>nextSmaller(n,-1);
        stack<int>s;
        for(int i=n-1;i>=0;i--){
            while(s.size()&&s.top()>nums[i]){
                s.pop();
            }
            int value=(s.size())?(s.top()):0;
            s.push(nums[i]);
            nums[i]-=value;
        }
        return nums;
    }
};
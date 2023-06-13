class Solution {
public:
    int buyChoco(vector<int>& nums, int money) {
        sort(nums.begin(),nums.end());
        int temp=money;
        money-=(nums[0]+nums[1]);
        if(money<0){
            return temp;
        }
        return money;
    }
};
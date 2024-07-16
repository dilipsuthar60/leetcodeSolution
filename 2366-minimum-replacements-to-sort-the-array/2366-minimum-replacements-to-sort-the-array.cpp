class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long cost=0;
        int n=nums.size();
        int prev=nums.back();
        for(int i=n-2;i>=0;i--){
            if(prev<nums[i]){
                int current=nums[i]/prev;
                if(nums[i]%prev){
                    current++;
                }
                prev=nums[i]/current;
                cost+=(current-1);
            }
            else{
                prev=nums[i];
            }
        }
        return cost;
    }
};
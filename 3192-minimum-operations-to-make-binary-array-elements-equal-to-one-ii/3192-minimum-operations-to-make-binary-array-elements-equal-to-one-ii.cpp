class Solution {
public:
    int minOperations(vector<int>& nums) {
        int flipCount=0;
        int n=nums.size();
        int flag=0;
        for(int i=0;i<n;i++)
        {
            int currentState = (nums[i]^(flag?1:0));
            if(currentState==0){
                flipCount++;
                flag^=1;
            }
        }
        return flipCount;
    }
};
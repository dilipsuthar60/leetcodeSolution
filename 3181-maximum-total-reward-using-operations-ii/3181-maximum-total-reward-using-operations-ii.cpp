class Solution {
public:
    int maxTotalReward(vector<int>& nums) {
        int n=nums.size();
        bitset<100005>dp,temp;
        int maskId=0;
        dp[0]=1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            while(maskId<nums[i]){
                temp[maskId++]=1;
            }
            dp|=(dp&temp)<<nums[i];
        }
        int index=dp.size()-1;
        while(!dp[index]){
            index--;
        }
        return index;
    }
};
class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int leftSum,rightSum;
        leftSum=rightSum=0;
        int n=nums.size();
        int maxCardPoints=0;
        for(int i=0;i<k;i++)
        {
            leftSum+=nums[i];
        }
        maxCardPoints=leftSum;
        for(int i=0;i<k;i++)
        {
            leftSum-=nums[k-1-i];
            rightSum+=nums[n-1-i];
            maxCardPoints=max(leftSum+rightSum,maxCardPoints);
        }
        return maxCardPoints;
    }
};
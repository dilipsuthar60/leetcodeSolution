class Solution {
public:
    int findMinMoves(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%n) return -1;
        int avg=sum/n;
        int currentSum=0;
        int ans=0;
        for(int i=0;i<n;i++){
            int req=nums[i]-avg;
            if(req>0){
                ans=max(ans,req);
            }
            currentSum+=req;
            ans=max(ans,abs(currentSum));
        }
        return ans;
    }
};
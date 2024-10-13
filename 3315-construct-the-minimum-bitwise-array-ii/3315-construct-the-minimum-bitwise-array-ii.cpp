class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            int result=1e9;
            for(int j=0;j<31;j++){
                if(nums[i]&(1<<j)){
                    int k=nums[i]-(1<<j);
                    if((k|(k+1))==nums[i]){
                        result=min(result,k);
                    }
                }
            }
            ans[i]=(result==1e9)?-1:result;
        }
        return ans;
    }
};
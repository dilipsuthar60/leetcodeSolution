class Solution {
public:
    const int mod=1e9+7;
    int numberOfGoodPartitions(vector<int>& nums) {
        int result=1;
        unordered_map<int,int>lastIndex;
        int n=nums.size();
        for(int i=0;i<n;i++){
            lastIndex[nums[i]]=i;
        }
        int j=lastIndex[nums.front()];
        for(int i=0;i<n;i++){
            if(i>j){
                result=(result*2)%mod;
            }
            j=max(j,lastIndex[nums[i]]);
        }
        return result;
    }
};
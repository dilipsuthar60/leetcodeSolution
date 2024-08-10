class Solution {
public:
    const int mod=1e9+7;
    int numberOfGoodPartitions(vector<int>& nums) {
        int result=1;
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]=i;
        }
        int j=max(0,mp[nums[0]]);
        for(int i=0;i<n;i++){
            if(i>j){
                result=(result*2)%mod;
            }
            j=max(j,mp[nums[i]]);
        }
        return result;
    }
};
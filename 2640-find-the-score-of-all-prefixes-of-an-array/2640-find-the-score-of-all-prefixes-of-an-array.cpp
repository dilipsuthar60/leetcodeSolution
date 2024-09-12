class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n=nums.size();
        vector<long long>prefix(n,0);
        int currentTillMaximum=0;
        for(int i=0;i<n;i++){
            currentTillMaximum=max(currentTillMaximum,nums[i]);
            prefix[i]=currentTillMaximum+nums[i];
            if(i){
                prefix[i]+=prefix[i-1];
            }
        }
        return prefix;
    }
};
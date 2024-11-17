class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>prefix(n+5,0);
        for(auto &it:queries){
            prefix[it[0]]++;
            prefix[it[1]+1]--;
        }
        for(int i=1;i<n;i++){
            prefix[i]+=prefix[i-1];
        }
        for(int i=0;i<n;i++){
            if(nums[i]>prefix[i]) return false;
        }
        return true;
    }
};
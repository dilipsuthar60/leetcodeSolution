class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<long long>prefix(n+1,0);
        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+nums[i];
        }
        vector<long long>ans;
        for(auto &value:queries){
            long long index=lower_bound(nums.begin(),nums.end(),value)-nums.begin();
            long long leftSum = value*index - (prefix[index]-prefix[0]);
            long long rightSum = (prefix.back()-prefix[index]) - value*(n-index);
            ans.push_back(leftSum+rightSum);
        }
        return ans;
    }
};
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        unordered_map<int,long long>prev;
        long long ans=0;
        for(int i=0,n=nums.size();i<n;i++){
            unordered_map<int,long long>curr;
            for(auto &[key,value]:prev){
                curr[key&nums[i]]+=value;
            }
            curr[nums[i]]++;
            ans+=curr[k];
            prev=curr;
        }
        return ans;
    }
};
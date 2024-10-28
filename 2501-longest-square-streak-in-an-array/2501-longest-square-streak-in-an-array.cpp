class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=-1;
        unordered_set<long long>s;
        for(auto &it:nums) s.insert(it);
        for(int i=0;i<n;i++){
            long long curr=nums[i];
            int currentLen=1;
            while(s.find(curr*curr)!=s.end()){
                currentLen++;
                curr=curr*curr;
            }
            ans=max(ans,currentLen);
        }
        return ans>=2?ans:-1;
    }
};
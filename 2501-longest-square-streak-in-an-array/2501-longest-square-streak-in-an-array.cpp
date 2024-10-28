class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=-1;
        unordered_map<long long,int>mp;
        for(int i=0;i<n;i++){
            int root=sqrt(nums[i]);
            if(root*root==nums[i]&&mp.find(root)!=mp.end()){
                mp[nums[i]]=mp[root]+1;
            }
            else{
                mp[nums[i]]=1;
            }
            ans=max(ans,mp[nums[i]]);
        }
        return ans>=2?ans:-1;
    }
};
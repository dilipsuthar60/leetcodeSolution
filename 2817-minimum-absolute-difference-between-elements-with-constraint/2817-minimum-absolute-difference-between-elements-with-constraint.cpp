class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int n=nums.size();
        set<int>s;
        int ans=1e9;
        for(int i=x;i<n;i++){
            s.insert(nums[i-x]);
            auto it=s.lower_bound(nums[i]);
            if(it!=s.end()){
                ans=min(ans,abs(*it-nums[i]));
            }
            if(it!=s.begin()){
                it--;
                ans=min(ans,abs(*it-nums[i]));
            }
        }
        return ans;
    }
};
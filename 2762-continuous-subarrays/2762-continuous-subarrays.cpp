class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        multiset<int>s;
        for(int i=0,j=0;i<n;i++){
            s.insert(nums[i]);
            while(s.size()&&(*s.rbegin()-*s.begin())>2){
                s.erase(s.find(nums[j++]));
            }
            ans+=(i-j+1);
        }
        return ans;
    }
};
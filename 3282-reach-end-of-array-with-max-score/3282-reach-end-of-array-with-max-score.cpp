class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        int n = nums.size();
        vector<int>right(n,n-1);
        stack<int>s;
        for(int i=n-1;i>=0;i--){
            while(s.size()&&nums[s.top()]<=nums[i]) s.pop();
            if(s.size()) right[i]=s.top();
            s.push(i);
        }
        long long ans=0;
        int v=0;
        while(v!=n-1){
            ans+=1ll*(right[v]-v)*nums[v];
            v=right[v];
        }
        return ans;
    }
};
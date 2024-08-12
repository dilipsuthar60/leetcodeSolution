class Solution {
public:
    vector<int> finalPrices(vector<int>& nums) {
        int n=nums.size();
        vector<int>nextSmaller(n,-1);
        stack<int>s;
        for(int i=n-1;i>=0;i--){
            while(s.size()&&s.top()>nums[i]){
                s.pop();
            }
            nextSmaller[i]=(s.size())?(s.top()):-1;
            s.push(nums[i]);
        }
        for(int i=0;i<n;i++){
            if(nextSmaller[i]==-1) continue;
            nums[i]-=nextSmaller[i];
        }
        return nums;
    }
};
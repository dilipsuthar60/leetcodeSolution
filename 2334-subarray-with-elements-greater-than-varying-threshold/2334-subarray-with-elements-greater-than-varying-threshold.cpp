class Solution {
public:
    vector<int>nextSmaller(vector<int>&nums){
        int n=nums.size();
        vector<int>smaller(n,n);
        stack<int>s;
        for(int i=n-1;i>=0;i--){
            while(s.size()&&nums[s.top()]>=nums[i]){
                s.pop();
            }
            smaller[i]=(s.size())?s.top():n;
            s.push(i);
        }
        return smaller;
    }
    vector<int>prevSmaller(vector<int>&nums){
        int n=nums.size();
        vector<int>smaller(n,-1);
        stack<int>s;
        for(int i=0;i<n;i++){
            while(s.size()&&nums[s.top()]>=nums[i]){
                s.pop();
            }
            smaller[i]=(s.size())?s.top():-1;
            s.push(i);
        }
        return smaller;
    }
    int validSubarraySize(vector<int>& nums, int threshold) {
        int n=nums.size();
        vector<int>left=prevSmaller(nums);
        vector<int>right=nextSmaller(nums);
        for(int i=0;i<n;i++){
            int range=right[i]-left[i]-1;
            if(nums[i]>(threshold/range)){
                return range;
            }
        }
        return -1;
    }
};
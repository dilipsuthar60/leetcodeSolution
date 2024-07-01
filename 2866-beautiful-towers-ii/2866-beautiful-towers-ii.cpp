class Solution {
public:
    vector<long long>findSum(vector<int>&nums){
        int n=nums.size();
        vector<long long>sum(n,0);
        vector<long long>currentMin(n,-1);
        stack<long long>s;
        s.push(0);
        sum[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            while(s.size()&&nums[s.top()]>=nums[i]){
                s.pop();
            }
            if(s.size()){
                currentMin[i]=s.top();
            }
            long long count=i-currentMin[i];
            sum[i]+=count*nums[i];
            if(currentMin[i]!=-1){
                sum[i]+=sum[currentMin[i]];
            }
            s.push(i);
        }
        return sum;
    }
    long long maximumSumOfHeights(vector<int>& nums) 
    {
        int n=nums.size();
        vector<long long>left=findSum(nums);
        reverse(nums.begin(),nums.end());
        vector<long long>right=findSum(nums);
        reverse(right.begin(),right.end());
        reverse(nums.begin(),nums.end());
        long long result=0;
        for(int i=0,n=nums.size();i<n;i++){
            result=max(result,left[i]+right[i]-nums[i]);
        }
        return result;
    }
};
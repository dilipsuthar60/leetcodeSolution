class Solution {
public:
    int getLowerBound(vector<int>&nums, int value){
        int size=nums.size();
        int left=0,right=size-1,mid=0,index=size;
        while(left<=right){
            mid=(left+right)/2;
            if(nums[mid]>value){
                index=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return index;
    }
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<long long>prefix(n+1,0);
        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+nums[i];
        }
        vector<long long>ans;
        for(auto &value:queries){
            long long index=getLowerBound(nums,value);
            long long leftSum = value*index - (prefix[index]-prefix[0]);
            long long rightSum = (prefix.back()-prefix[index]) - value*(n-index);
            ans.push_back(leftSum+rightSum);
        }
        return ans;
    }
};
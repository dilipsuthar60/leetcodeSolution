class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n=nums.size();
        int last=-1e9;
        sort(nums.begin(),nums.end());
        int count=0;
        for(int i=0;i<n;i++){
            int x=max(last+1,nums[i]-k);
            if(x>nums[i]+k){
                continue;
            }
            last=x;
            count++;
        }
        return count;
    }
};
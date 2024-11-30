class Solution {
public:
    bool find(vector<int>&nums,int mid,int op){
        int count=0;
        for(int i=0;i<nums.size();i++){
            count+=(nums[i]+mid-1)/mid - 1;
        }
        return count<=op;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l=1;
        int r=1e9;
        int ans=0;
        while(l<=r){
            int mid=(l+r)/2;
            if(find(nums,mid,maxOperations)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};
class Solution {
public:
    bool find(vector<int>&nums,int mid,int p){
        int count=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]-nums[i]<=mid){
                i+=1;
                count++;
            }
        }
        return count>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int left=0,right=1e9+10;
        int ans=0;
        while(left<=right){
            int mid=(left+right)/2;
            if(find(nums, mid, p)){
                ans=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return ans;
    }
};
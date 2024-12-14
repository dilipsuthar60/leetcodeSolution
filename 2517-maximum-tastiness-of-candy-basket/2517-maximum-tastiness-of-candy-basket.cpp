class Solution {
public:
    bool find(vector<int>&nums,int k,int mid){
        int prev=nums.front();
        int count=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]-prev>=mid){
                prev=nums[i];
                count++;
            }
        }
        return count>=k;
    }
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(),price.end());
        int ans=0;
        int l=0;
        int r=1e9;
        while(l<=r){
            int mid=(l+r)/2;
            if(find(price,k,mid)){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};
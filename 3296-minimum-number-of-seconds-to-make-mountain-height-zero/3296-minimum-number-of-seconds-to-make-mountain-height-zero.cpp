class Solution {
public:
    bool find(vector<int>&nums,long long height,long long time){
        int n=nums.size();
        for(int i=0;i<n;i++){
            long long l=0;
            long long r=1e6;
            long long reduce=0;
            while(l<=r){
                long long mid=(l+r)/2;
                if(1ll*nums[i]*(mid*(mid+1)/2)<=time){
                    reduce=mid;
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
            height-=reduce;
        }
        return height<=0;
    }
    long long minNumberOfSeconds(int height, vector<int>& worker) {
        long long l=0;
        long long r=1e18;
        long long ans=0;
        while(l<=r){
            long long mid=(l+r)/2;
            if(find(worker,height,mid)){
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
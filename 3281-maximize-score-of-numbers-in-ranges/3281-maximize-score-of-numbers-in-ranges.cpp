class Solution {
public:
    bool find(vector<int>&nums,long long mid,long long d){
        long long prev=nums.front();
        for(int i=1,n=nums.size();i<n;i++){
            long long next=max(prev+mid,nums[i]+0ll);
            if(next>nums[i]+d) return false;
            prev=next;
        }
        return true;
    }
    int maxPossibleScore(vector<int>&nums, int d) {
        sort(nums.begin(),nums.end());
        long long l=0;
        long long r=1e18+7;
        long long ans=0;
        while(l<=r){
            long long mid=(l+r)/2;
            if(find(nums,mid,d)){
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
class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n=grades.size();
        int l=0;
        int r=n;
        int ans=0;
        while(l<=r){
            long long mid=(l+r)/2;
            if((mid*(mid+1))/2<=n){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return r;
    }
};
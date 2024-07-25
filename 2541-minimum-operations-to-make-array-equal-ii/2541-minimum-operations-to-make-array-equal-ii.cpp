class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        if(k==0){
            return nums1==nums2?0:-1;
        }
        long long plus=0;
        long long minus=0;
        for(int i=0;i<n;i++){
            int diff=nums1[i]-nums2[i];
            if(diff%k) return -1;
            if(diff<0){
                minus+=diff;
            }
            if(diff>0){
                plus+=diff;
            }
        }
        if(plus==abs(minus)){
            if(plus%k==0)
            return plus/k;
        }
        return -1;
    }
};
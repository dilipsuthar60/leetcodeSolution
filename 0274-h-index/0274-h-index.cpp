class Solution {
public:
    int hIndex(vector<int>& nums) {
        int n=nums.size();
        int hash[n+1];
        memset(hash,0,sizeof(hash));
        for(int i=0;i<n;i++){
            if(nums[i]>=n) hash[n]++;
            else hash[nums[i]]++;
        }
        int sum=0;
        for(int i=n;i>=0;i--){
            sum+=hash[i];
            if(sum>=i) return i;
        }
        return 0;
    }
};
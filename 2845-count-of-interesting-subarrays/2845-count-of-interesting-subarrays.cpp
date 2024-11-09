class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]%modulo==k){
                nums[i]=1;
            }
            else{
                nums[i]=0;
            }
        }
        unordered_map<long long,long long>mp={{0,1}};
        long long sum=0;
        long long count=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            sum%=modulo;
            int need=(sum-k+modulo)%modulo;
            count+=mp[need];
            mp[sum]++;
        }
        return count;
    }
};
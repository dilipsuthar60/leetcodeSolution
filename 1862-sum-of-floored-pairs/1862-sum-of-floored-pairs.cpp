class Solution {
public:
    const int MAX=1e5+5;
    const int mod= 1e9+7;
    int sumOfFlooredPairs(vector<int>& nums) {
        vector<long long>prefix(MAX,0);
        unordered_map<int,int>mp;
        int n=nums.size();
        for(auto &it:nums){
            prefix[it]++;
            mp[it]++;
        }
        for(int i=1;i<MAX;i++){
            prefix[i]+=prefix[i-1];
            prefix[i]%=mod;
        }
        long long ans=0;
        
        for(auto &[key,value]:mp){
            int num=key;
            long long result=0;
            for(int start=num;start<MAX;start+=num){
                int end=min(MAX-1,start+num-1);
                long long rangeSum = (prefix[end]-prefix[start-1])%mod;
                long long floorValue = start/num;
                result+=floorValue*rangeSum;
                result%=mod;
            }
            ans+=result*value;
            ans%=mod;
        }
        return ans;
    }
};